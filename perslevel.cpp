#include "perslevel.h"
#include "ui_perslevel.h"

PersLevel::PersLevel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PersLevel)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);

    model->setTable("pers");
    model->setSort(0, Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, "����");
    model->setHeaderData(1, Qt::Horizontal, "����");
    model->setHeaderData(2, Qt::Horizontal, "ְ��");
    model->setHeaderData(3, Qt::Horizontal, "��������");
    model->setHeaderData(4, Qt::Horizontal, "�Ա�");
    model->setHeaderData(5, Qt::Horizontal, "�ȼ�");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(3, 150);
}

PersLevel::~PersLevel()
{
    delete ui;
}

void PersLevel::on_pushButton_commit_clicked()
{
    model->database().transaction(); //��ʼ�������
    if (model->submitAll()) // �ύ���б��޸ĵ����ݵ����ݿ���
    {
        model->database().commit(); //�ύ�ɹ������������޸����ݿ�����
    } else {
        model->database().rollback(); //�ύʧ�ܣ�����ع�
        QMessageBox::warning(this, tr("����"),tr("���ݿ����: %1").arg(model->lastError().text()));
    }
}



void PersLevel::on_pushButton_delete_clicked()
{
    int curRow = ui->tableView->currentIndex().row();     //��ȡѡ�е���
    model->removeRow(curRow);     //ɾ������
    int ok = QMessageBox::warning(this,tr("ɾ����ǰ��!"),tr("��ȷ��ɾ����ǰ����"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //�����ɾ��������
    }else {
        model->submitAll(); //�����ύ�������ݿ���ɾ������
    }
}

void PersLevel::on_pushButton_add_clicked()
{
    int rowNum = model->rowCount(); //��ñ������
    int persid = model->rowCount()+1;
    model->insertRow(rowNum); //���һ��
    model->setData(model->index(rowNum,0),persid);
    //model->submitAll(); //����ֱ���ύ
}

void PersLevel::on_pushButton_revert_clicked()
{
    model->revertAll(); //�����޸�
    QMessageBox::warning(this, tr("�����ɹ�"),tr("�����ɹ�"));

}
