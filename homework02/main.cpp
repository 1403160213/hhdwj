#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QList>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{
   QStringList stud_data;
} studData;

QDebug operator<< (QDebug d, const studData &data) {
for(int i=0;i<data.stud_data.size();i++)

    {

        d<<data.stud_data.at(i);

    }

    qDebug()<<"";

    return d;
    // 补全运算符重载函数
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:

        result=d1.stud_data.at(currentColumn)>d2.stud_data.at(currentColumn);

                break;
    }
    return result;
}


class ScoreSorter
{

  public:
    QString datafile;

    ScoreSorter(QString dataFile);

    void readFile();

    void doSort();

private:

    QString Fileroute;

    QList<studData > data;

    studData listtitle;

    void printfile(quint8 t);
}



ScoreSorter::ScoreSorter(QString dataFile)
{
this->Fileroute=dataFile;
}


 void ScoreSorter::readFile()
{
     QFile file(this->Fileroute);   //只读方式打开文件

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        qDebug()<<"Can't open the file"<<endl;


         studData tempstudent;

        QString Title(mfile.readLine());

        title= Title.split(" ", QString::SkipEmptyParts);

    while(!mfile.atEnd()) {

        QString str(mfile.readLine());

        tempstudent.st = str.split(" ", QString::SkipEmptyParts);

        if((tempstudent.st).last() == "\n") tempstudent.st.removeLast();

        if(tempstudent.st.size()==0) continue;

        student.append(tempstudent);

    }

    mfile.close();

}

void ScoreSorter::doSort()

{

    for(int k=1; k<this->txttitle.stud.size(); k++)

    {

        myCmp mycmp(k-1);    //初始化对象

        std::sort(this->date.begin() , this->date.end() , mycmp );  //排序



        qDebug()<<"排序后输出，当前排序第 "<< k+1 <<" 列：";

        qDebug()<< "   "<<(this->listtitle);  



        for(int k=0;k<this->date.size();k++)  qDebug() << this->date.at(k);

        qDebug()<<"-----------------------------------------------------------------------------------------\n";



        this->printfile(k+1); //排序data 输出到文件

    }

}
void ScoreSorter::printfile(quint8 t)

{

    QFile file("sorted_"+this->dataroute);



    file.open(QIODevice::ReadWrite | QIODevice::Append);



    QTextStream stream(&file);

    stream.setCodec("UTF-8"); 

    stream<<QString("排序后输出，当前排序第 ")<<currentColumn <<QString(" 列：")<<"\r\n";



    for(int m=0;m<this->listtitle.stud.size();m++)

    {

        stream<<"   "<<this->listtitle.stud.at(m);

    }

        stream<<"\r\n";



    for(int p=0;p<this->date.size();i++)            //输出内容

    {

        for(int p=0;p<this->listtitle.stud.size();p++)

        stream<<this->date.at(p).stud.at(m)<<"\t";

        stream<<"\r\n";

    }





    stream<<"------------------------------------------------------------------"<<"\r\n\r\n";

    file.close();

}



int main()
{
    
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
