#include "achievementwindow.h"
#include "ui_achievementwindow.h"
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QPixmap>
#include <QImage>

AchievementWindow::AchievementWindow(/*const QVector<Achievement> &achievementList, */QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AchievementWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
    ui->backBtn->setStyleSheet("QPushButton{\
                                background-color: rgb(225, 225, 225);\
                                border:2px groove gray;\
                                border-radius:10px;\
                                padding:2px 4px;\
                                border-style: outset;\
                                }\
                                \
                                QPushButton:hover{\
                                background-color:rgb(229, 241, 251);\
                                color: black;\
                                }\
                                \
                                QPushButton:pressed{\
                                background-color:rgb(204, 228, 247);\
                                border-style: inset;\
                                }");

//    QWidget *backdrop = new QWidget;                     //创建滚动显示区域幕布
//    QHBoxLayout *layout = new QHBoxLayout(backdrop);     //创建布局

////    imagePathList << QString("MainIcon.png")
////              << QString("resourse/images/Icons/Main_Color/tomato1.png")
////              << QString("MainIcon.png")
////              << QString("resourse/images/Icons/Main_Color/tomato1.png")
////              << QString("MainIcon.png")
////              << QString("MainIcon.png")
////              << QString("MainIcon.png");

//    //进行界面的布局
//    for(int i = 0; i < achievementList.size(); i++){
//        QWidget *tmpWidgetPtr = new QWidget();                                                                //当前的成就的widget
//        tmpWidgetPtr->setObjectName("tmpWidget");                                                             //设置ui对象名
//        tmpWidgetPtr->setStyleSheet(QString("QWidget#tmpWidget{border:1px solid black;border-radius:15px}")); //边框设置为黑色，圆角
////        tmpWidgetPtr->setFixedWidth(300);
//        QVBoxLayout *tmpLayout = new QVBoxLayout(tmpWidgetPtr);                                               //每个成就内部的布局

//        QLabel *imageLabel = new QLabel();                                        //当前成就的图片的标签
//        imageLabel->setAlignment(Qt::AlignHCenter);                               //图片居中
//        QImage *img = new QImage();;
//        try{
//            if (img->load(QString(":/images/%1").arg(imagePathList[i]))){             //添加图片路径
//                throw QString("Successfully loaded image %1").arg(i);
//            }
//            else {
//                throw QString("Failed to load image %1").arg(i);
//            }
//        }
//        catch(QString e){
//            qDebug(e.toLatin1());
//        }
//        QImage *gray_img = new QImage();                                          //转化为灰度图
//        *gray_img = img->convertToFormat(QImage::Format_Grayscale16, Qt::AutoColor);
//        QPixmap *pix_img = new QPixmap();                                         //转化为Pixmap，用Pixmap显示
//        //成就已达成的状态，显示彩色图片
//        if (achievementList[i].getState()){
//            pix_img->convertFromImage(*img);
//        }
//        //成绩未达成的状态，显示灰色图片
//        else {
//            pix_img->convertFromImage(*gray_img);
//        }
//        *pix_img = pix_img->scaled(150, 150, Qt::KeepAspectRatio);                //设置图片分辨率(大小)，保持高宽比
//        imageLabel->setPixmap(*pix_img);                                          //将图片放入标签
////        tmpWidgetPtr->setFixedWidth(pix_img->width());
////        tmpWidgetPtr->resize(imageLabel->width() + 2*LABELMARGIN, tmpWidgetPtr->height());
//        imageLabel->setScaledContents(true); //图片充满label
////        imageLabel->setSizePolicy(QSizePolicy(Qt::AspectRatioMode));

//        //添加stretch?

//        QLabel *achievementName = new QLabel(achievementList[i].getName());       //当前成就的名字
//        achievementName->setAlignment(Qt::AlignHCenter);                          //文本居中
////        achievementName->setMaximumHeight(40);                                    //设置成就名高度最大值
//        QLabel *howToAchieve = new QLabel(achievementList[i].getHowToAchieve());  //当前成就达成条件
//        howToAchieve->setAlignment(Qt::AlignHCenter);                             //文本居中
////        howToAchieve->setMaximumHeight(40);                                       //设置达成条件高度最大值

//        tmpLayout->addWidget(imageLabel);      //将图片放入当前成就的布局
//        tmpLayout->addWidget(achievementName); //将成就名放入当前成就的布局
//        tmpLayout->addWidget(howToAchieve);    //将成就达成条件放入当前布局
//        layout->addWidget(tmpWidgetPtr);       //将每个成就的widget放入layout
//    }
//    //最后将幕布放入scrollArea
//    ui->scrollArea->setWidget(backdrop);

//    //获取所有控件
//    allChildWidgets = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
//    //获取所有控件的大小和位置
//    foreach (auto widget, allChildWidgets) {
//        allWidgetRect.insert(widget, QRect(widget->x(), widget->y(), widget->width(), widget->height()));
//    }
}

//AchievementWindow::AchievementWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::AchievementWindow)
//{
//    ui->setupUi(this);
//}

AchievementWindow::~AchievementWindow()
{
    delete ui;
}

void AchievementWindow::MaintoAchievement(QVector<Achievement> achievementList)
{
    QWidget *backdrop = new QWidget;                     //创建滚动显示区域幕布
    QHBoxLayout *layout = new QHBoxLayout(backdrop);     //创建布局

    //    imagePathList << QString("MainIcon.png")
    //              << QString("resourse/images/Icons/Main_Color/tomato1.png")
    //              << QString("MainIcon.png")
    //              << QString("resourse/images/Icons/Main_Color/tomato1.png")
    //              << QString("MainIcon.png")
    //              << QString("MainIcon.png")
    //              << QString("MainIcon.png");

    //进行界面的布局
    for(int i = 0; i < achievementList.size(); i++){
        QWidget *tmpWidgetPtr = new QWidget();                                                                //当前的成就的widget
        tmpWidgetPtr->setObjectName("tmpWidget");                                                             //设置ui对象名
        tmpWidgetPtr->setStyleSheet(QString("QWidget#tmpWidget{border:1px solid black;border-radius:15px}")); //边框设置为黑色，圆角
        //        tmpWidgetPtr->setFixedWidth(300);
        QVBoxLayout *tmpLayout = new QVBoxLayout(tmpWidgetPtr);                                               //每个成就内部的布局

        QLabel *imageLabel = new QLabel();                                        //当前成就的图片的标签
        imageLabel->setAlignment(Qt::AlignHCenter);                               //图片居中
        QImage *img = new QImage();;
        try{
            if (img->load(QString(":/images/%1").arg(imagePathList[i]))){             //添加图片路径
                throw QString("Successfully loaded image %1").arg(i);
            }
            else {
                throw QString("Failed to load image %1").arg(i);
            }
        }
        catch(QString e){
            qDebug(e.toLatin1());
        }
        QImage *gray_img = new QImage();                                          //转化为灰度图
        *gray_img = img->convertToFormat(QImage::Format_Grayscale16, Qt::AutoColor);
        QPixmap *pix_img = new QPixmap();                                         //转化为Pixmap，用Pixmap显示
        //成就已达成的状态，显示彩色图片
        if (achievementList[i].getState()){
            pix_img->convertFromImage(*img);
        }
        //成绩未达成的状态，显示灰色图片
        else {
            pix_img->convertFromImage(*gray_img);
        }
        *pix_img = pix_img->scaled(150, 150, Qt::KeepAspectRatio);                //设置图片分辨率(大小)，保持高宽比
        imageLabel->setPixmap(*pix_img);                                          //将图片放入标签
        //        tmpWidgetPtr->setFixedWidth(pix_img->width());
        //        tmpWidgetPtr->resize(imageLabel->width() + 2*LABELMARGIN, tmpWidgetPtr->height());
        imageLabel->setScaledContents(true); //图片充满label
        //        imageLabel->setSizePolicy(QSizePolicy(Qt::AspectRatioMode));

        //添加stretch?

        QLabel *achievementName = new QLabel(achievementList[i].getName());       //当前成就的名字
        achievementName->setAlignment(Qt::AlignHCenter);                          //文本居中
        //        achievementName->setMaximumHeight(40);                                    //设置成就名高度最大值
        QLabel *howToAchieve = new QLabel(achievementList[i].getHowToAchieve());  //当前成就达成条件
        howToAchieve->setAlignment(Qt::AlignHCenter);                             //文本居中
        //        howToAchieve->setMaximumHeight(40);                                       //设置达成条件高度最大值

        tmpLayout->addWidget(imageLabel);      //将图片放入当前成就的布局
        tmpLayout->addWidget(achievementName); //将成就名放入当前成就的布局
        tmpLayout->addWidget(howToAchieve);    //将成就达成条件放入当前布局
        layout->addWidget(tmpWidgetPtr);       //将每个成就的widget放入layout
    }
    //最后将幕布放入scrollArea
    ui->scrollArea->setWidget(backdrop);

    //获取所有控件
    allChildWidgets = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
    //获取所有控件的大小和位置
    foreach (auto widget, allChildWidgets) {
        allWidgetRect.insert(widget, QRect(widget->x(), widget->y(), widget->width(), widget->height()));
    }
    update();
    this->show();
}

void AchievementWindow::on_backBtn_clicked()
{
    emit JumptoMain();
    this->close();
}

void AchievementWindow::changeTomatoNum(int tomatoNum)
{
    //仅起到修改界面显示的数据的功能
    ui->numOfTomato->setText(QString("%1").arg(tomatoNum));
    update();
}

void AchievementWindow::resizeEvent(QResizeEvent *event)
{
    float width = this->width() * 1.0 / 800;
    float height = this->height() * 1.0 / 500;
    for (auto i = allWidgetRect.begin(); i != allWidgetRect.end(); i++){
        i.key()->setGeometry(i.value().x() * width, i.value().y() *height, i.value().width() * width, i.value().height() * height);
    }
    QWidget::resizeEvent(event);
}

void AchievementWindow::closeEvent(QCloseEvent *event)
{
    emit JumptoMain();
    QMainWindow::closeEvent(event);
}

void AchievementWindow::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
