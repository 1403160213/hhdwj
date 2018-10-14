#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include<algorithm>
#include <array>
#define STR(s)  _STR(s)
#define _STR(s)   #s

using namespace std;
#define  WORD_LO(xxx)  (((xxx) & 255))         //取32位中的最低8位
#define  WORD_HLO(xxx)  ((((xxx) >>8) & 255))  //取32位中的次低8位
#define  WORD_LHI(xxx)  (((xxx) >> 16)& 255)   //取32位中的次高8位
#define  WORD_HI(xxx)  (((xxx) >> 24))         //取32位中的最高8位

#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )//取最大值
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )//取最小值

#define  at(x) values.at(x)                    //取数组的数

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    unsigned int test=0x12345678;
    QList<qint8> values;

    values<<WORD_HI(test);
    values<<WORD_LHI(test);
    values<<WORD_HLO(test);
    values<<WORD_LO(test);
    qDebug("原始数值:0x%x==%d",test,test);       //显示原始的数值
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",//显示各个8位数值
           at(0),at(0),at(1),at(1),
           at(2),at(2),at(3),at(3));
    //高低8位比较大小
    qDebug("最高8位和次高8位最大值：0x%x(%d)"       //比较最高8位和次高8位大小
           ,MAX(at(0),at(1)),MAX(at(0),at(1)));
    qDebug("次低8位和最低8位最大值：0x%x(%d)"       //比较次低8位和最低8位大小
           ,MIN(at(3),at(2)),MAX(at(3),at(2)));


    //重新组合
    unsigned int new_test=at(1)+(at(3)<<8)+(at(0)<<16)+(at(2)<<24);
    qDebug("组合后的数值:0x%x(%d)",new_test,new_test);

    //排序
    qDebug()<<"排序前："<<values;           //显示原序列
    std::sort(values.begin(),values.end(),std::greater<qint8>());
    qDebug()<<"排序后："<<values;           //显示排序后的序列
}
