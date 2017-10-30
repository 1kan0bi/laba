#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&generation, SIGNAL(clicked()), SLOT(on_generation_clicked()));
    connect(&sort, SIGNAL(clicked()), SLOT(on_sort_clicked()));
    connect(&bubble, SIGNAL(clicked()), SLOT(on_bubble_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bubble_clicked()
{
    ui->time_text->clear();
   unsigned int start_time =  clock();
    ui->after->clear();
    for (int i = 0; i <vec.size(); i++) {
        for (int j = 0; j < vec.size()-1; j++) {
            if (vec[j] > vec[j + 1]) {

                int temp;
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time)/1000;
    for(int i=0; i<vec.size(); i++)
    {
        str += QString::number(vec[i]);
        str += " ";
    }
    ui->after->append(str);
    time_sec+=QString::number(search_time);
    ui->time_text->append(time_sec + "msec");
    search_time=0;
    str.clear();
    time_sec.clear();
}

void MainWindow::on_sort_clicked()
{
    unsigned int start_time =  clock();
    ui->after->clear();
    ui->time_text->clear();
    std::sort(vec.begin(), vec.end());
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
       for(int i=0; i<vec.size(); i++)
       {
           str += QString::number(vec[i]);
           str +=" ";

       }
       time_sec+=QString::number(search_time);
       ui->after->append(str);
       ui->time_text->append(time_sec + "msec");
       search_time=0;
        str.clear();
        time_sec.clear();
}

void MainWindow::on_generation_clicked()
{
    ui->before->clear();
    srand(time(NULL));
    for(int i=0; i<vec.size(); i++)
        vec[i]=rand()%100;

    for(int i=0; i<vec.size(); i++)
    {
        str += QString::number(vec[i]);
        str += " ";
    }
    ui->before->append(str);
    str.clear();

}
