#include <QCoreApplication>
#include<QDebug>
//定义学生信息类；
class st_inf
 {
 public:
    QString name;
     int number;
     int course1;
     int course2;
 };
//姓名函数；
bool sort_name(st_inf s1,st_inf s2)
{
    if (s1.name>s2.name)
        return 1;
    else
        return 0;
}
//学号函数；
bool sort_number(st_inf s1,st_inf s2)
{
    if (s1.number>s2.number)
        return 1;
    else
        return 0;
}
//course1排序函数；
bool sort_course1(st_inf s1,st_inf s2)
{
    if (s1.course1>s2.course1)
        return 1;
    else
        return 0;
}
//course2排序函数；
bool sort_course2(st_inf s1,st_inf s2)
{
    if (s1.course2>s2.course2)
        return 1;
    else
        return 0;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//
    st_inf std1,std2,std3,std4;

    std1.name="鲁智深";
    std1.number=1403130209;
    std1.course1=80;
    std1.course2=72;

    std2.name="林冲";
    std2.number=1403140101;
    std2.course1=82;
    std2.course2=76;

    std3.name="宋江";
    std3.number=1403140102;
    std3.course1=76;
    std3.course2=85;

    std4.name="武松";
    std4.number=1403140103;
    std4.course1=88;
    std4.course2=80;

    //学生信息列表；
    QList<st_inf>list;
    list<<std1<<std2<<std3<<std4;
    //输出
    qDebug("原始数据：");
    qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    for(int i=0;i<4;i++)
    {
        qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).course1<<"\t"<<list.at(i).course2;
    }
    qDebug("---------");


    std::sort(list.begin(),list.end(),sort_name);
    qDebug("按姓名排序");
    qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    for(int i=0;i<4;i++)
    {
        qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).course1<<"\t"<<list.at(i).course2;
    }
    qDebug("---------");


    std::sort(list.begin(),list.end(),sort_number);
    qDebug("按学号排序");
    qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    for(int i=0;i<4;i++)
    {
        qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).course1<<"\t"<<list.at(i).course2;
    }
    qDebug("---------");


    std::sort(list.begin(),list.end(),sort_course1);
    qDebug("按课程1排序");
    qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    for(int i=0;i<4;i++)
    {
        qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).course1<<"\t"<<list.at(i).course2;
    }
    qDebug("---------");

    std::sort(list.begin(),list.end(),sort_course2);
    qDebug("按课程2排序");
    qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    for(int i=0;i<4;i++)
    {
        qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).course1<<"\t"<<list.at(i).course2;
    }
    return a.exec();
}

