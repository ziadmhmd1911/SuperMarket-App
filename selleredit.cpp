#include "selleredit.h"
#include "ui_selleredit.h"
#include <QMessageBox>
SellerEdit::SellerEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerEdit)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

SellerEdit::~SellerEdit()
{
    delete ui;
}

void SellerEdit::on_pushButton_clicked()
{
    ui->treeWidget->clear();


    //ui->added->setText(supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[0].getName());

    ui->treeWidget->setColumnCount(4);
    QStringList lables;
    lables << "Product Name" << "Product Quantity" << "Product Price" << "Product Category";
    ui->treeWidget->setHeaderLabels(lables);

        for (int i=0 ; i<this->supermarketobject.products.size(); i++) {
            if (supermarketobject.products[i].getSellerId() == supermarketobject.sellers[supermarketobject.loggedInIndex].getId()) {
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
        root->setText(0 , this->supermarketobject.products[i].getName());
        root->setText(1 , this->supermarketobject.products[i].getQuantity());
        root->setText(2 , this->supermarketobject.products[i].getPrice());
        root->setText(3 , this->supermarketobject.products[i].getCategory());
    }
}
}


void SellerEdit::on_pushButton_2_clicked()
{
    if(supermarketobject.customers.empty())
    {
        supermarketobject.readFromFileIntoCustomer();
        supermarketobject.readFromFileIntoSeller();
        supermarketobject.readFromFileIntoProduct();
        supermarketobject.readFromFileIntoCustomerCart();
        supermarketobject.readindexfromfileintovariable();
    }

    QString productname = ui->lineEdit->text();
    QString productquantity = ui->lineEdit_2->text();
    bool flag = false;
    bool ok;
    int index;
    for (int i=0 ; i<this->supermarketobject.products.size(); i++) {
        if (supermarketobject.products[i].getName() == productname) {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag) {
        if (supermarketobject.products[index].getSellerId() == supermarketobject.sellers[supermarketobject.loggedInIndex].getId()) {
              int gettquann = supermarketobject.products[index].getQuantity().toInt(&ok);
              int editedquann = productquantity.toInt(&ok);
              int sum = gettquann + editedquann;
              QString newquan = QString::number(sum);
              supermarketobject.products[index].setQuantity(newquan);
              QMessageBox::information(this , "Edit" , "Product Quantity Increased by"" "+productquantity+" "+"And Become"+newquan);
              //supermarketobject.writeAllFiles();
        }
        else {
            QMessageBox::warning(this , "Edit" , "Not Your Product");
        }
    }
    else {
            QMessageBox::warning(this , "Edit" , "Not Found");
    }

}
