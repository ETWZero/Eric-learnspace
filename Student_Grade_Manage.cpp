#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class Student;
class SmallStudent;
class MediumStudent;
class BigStudent;
fstream file;
string str;

vector <SmallStudent> smallstudents;
vector <MediumStudent> mediumstudents;
vector <BigStudent> bigstudents;

void init();
int string2int(string);
double string2double(string);
string double2string(double);
void show_main();
void show_manage();
void show_add();
void show_find();
void show_output();
int input();
void main_loop();
void add_loop();
void manage_loop();
void add_smallstudent();
void add_mediumstudent();
void add_bigstudent();
void find_loop();
int find_num(string);
int find_name(string);
void file_read();
void file_write();
void output_loop();
string input_num();
string inputName();
void output_small();
void output_medium();
void output_big();
void output_all();


int main()
{
    init();
    main_loop();
    return 0;
}

void init()
{
    system("color a0");
}

int string2int(string str)
{
    return atoi(str.c_str());
}
double string2double(string str)
{
    return atoi(str.c_str());
}
string double2string(double n)
{
    std::stringstream ss;
    std::string str;
    ss<<n;
    ss>>str;
    return str;
}

class Student
{
public:
    void input_sch_num()
    {
        cout<<"������ѧ�ţ�";
        cin>>str;
        for(int i=0;sizeof(sch_num);i++)
        {
            if(sch_num[i]<48||sch_num[i]>58)
            {
                cout<<"���������������������룡"<<endl;
                input_sch_num();
            }
        }
        sch_num = str;
    }
    void input_name()
    {
        cout<<"������������";
        cin>>name;
    }
    void input_classes()
    {
        cout<<"������༶��";
        cin>>classes;
    }
    void input_gender()
    {
        cout<<"�������Ա���/Ů�ֱ�Ϊ��д��M/F����";
        cin>>str;
        gender = str[0];
        if(gender!='M'&&gender!='F')
        {
            cout<<"���������������������룡"<</*gender<<*/endl;
            input_gender();
        }
        str = "";
    }
    void input_age()
    {
        cout<<"���������䣺";
        cin>>str;
        age = string2int(str);
        if(age == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_age();
        }
        str = "";
    }

    void output()
    {
    cout<<setfill(' ')<<setw(12)<<sch_num<<setfill(' ')<<setw(8)<<name<<setfill(' ')<<setw(8)<<classes<<setfill(' ')<<setw(8)<<gender<<setfill(' ')<<setw(8)<<age<<endl;
    }



    string get_num()
    {
        return sch_num;
    }
    string get_name()
    {
        return name;
    }
    string get_classes()
    {
        return classes;
    }
    int get_age()
    {
        return age;
    }
    char get_gender()
    {
        return gender;
    }

protected:
    string sch_num;
    string name;
    string classes;
    string str;
    char gender;
    int age;
};

class SmallStudent:public Student
{
public:
    void input_ch_score()
    {
        cout<<"���������ķ�����";
        cin>>str;
        ch_score = string2int(str);
        if(ch_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_ch_score();
        }
        str = "";
    }
    void input_ma_score()
    {
        cout<<"��������ѧ������";
        cin>>str;
        ma_score = string2int(str);
        if(ma_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_ma_score();
        }
        str = "";
    }
    void input_en_score()
    {
        cout<<"������Ӣ�������";
        cin>>str;
        en_score = string2int(str);
        if(en_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_en_score();
        }
        str = "";
    }
    void output_()
    {
    cout<<setfill(' ')<<setw(12)<<sch_num<<setfill(' ')<<setw(8)<<name<<setfill(' ')<<setw(8)<<classes<<setfill(' ')<<setw(8)<<gender<<setfill(' ')<<setw(8)<<age;
    cout<<setfill(' ')<<setw(12)<<ch_score<<setfill(' ')<<setw(12)<<ma_score<<setfill(' ')<<setw(12)<<en_score<<endl;
    }

    void file_input_small()
    {
        file>>sch_num>>name>>gender>>age>>classes>>ch_score>>ma_score>>en_score;
    }

    int get_ch_score()
    {
        return ch_score;
    }
    int get_ma_score()
    {
        return ma_score;
    }
    int get_en_score()
    {
        return en_score;
    }
protected:
    int ch_score;
    int ma_score;
    int en_score;
};

class MediumStudent:public SmallStudent
{
public:
    void input_gr_score()
    {
        cout<<"��������������";
        cin>>str;
        gr_score = string2int(str);
        if(gr_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_gr_score();
        }
        str = "";
    }
    void input_hi_score()
    {
        cout<<"��������ʷ������";
        cin>>str;
        hi_score = string2int(str);
        if(hi_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_hi_score();
        }
        str = "";
    }
    void output__()
    {
/*    cout<<"ѧ�ţ�"<<sch_num<<"    ������"<<name<<"    �༶��"<<classes<<"    �Ա�"<<gender<<"    ���䣺"<<age<<endl;
    cout<<"���ĳɼ���"<<ch_score<<"    ��ѧ�ɼ���"<<ma_score<<"    Ӣ��ɼ���"<<en_score<<endl;
    cout<<"����ɼ���"<<gr_score<<"    ��ʷ�ɼ���"<<hi_score<<endl;*/
    cout<<setfill(' ')<<setw(12)<<sch_num<<setfill(' ')<<setw(8)<<name<<setfill(' ')<<setw(8)<<classes<<setfill(' ')<<setw(8)<<gender<<setfill(' ')<<setw(8)<<age;
    cout<<setfill(' ')<<setw(12)<<ch_score<<setfill(' ')<<setw(12)<<ma_score<<setfill(' ')<<setw(12)<<en_score<<setfill(' ')<<setw(12)<<gr_score<<setfill(' ')<<setw(12)<<hi_score<<endl;
    }
    int get_gr_score()
    {
        return gr_score;
    }
    int get_hi_score()
    {
        return hi_score;
    }

    void file_input_medium()
    {
        file>>sch_num>>name>>gender>>age>>classes>>ch_score>>ma_score>>en_score>>gr_score>>hi_score;
    }

protected:
    int gr_score;
    int hi_score;
};

class BigStudent:public Student
{
public:
    void input_pro_score()
    {
        cout<<"������רҵ�η�����";
        cin>>str;
        pro_score = string2int(str);
        if(pro_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_pro_score();
        }
        str = "";
    }
    void input_adma_score()
    {
        cout<<"���������������";
        cin>>str;
        adma_score = string2int(str);
        if(adma_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_adma_score();
        }
        str = "";
    }
    void input_program_score()
    {
        cout<<"������������̷�����";
        cin>>str;
        program_score = string2int(str);
        if(program_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_program_score();
        }
        str = "";
    }
    void input_en_score()
    {
        cout<<"������Ӣ�������";
        cin>>str;
        en_score = string2int(str);
        if(en_score == 0)
        {
            cout<<"���������������������룡"<<endl;
            input_en_score();
        }
        str = "";
    }
    void output_()
    {
    cout<<setfill(' ')<<setw(12)<<sch_num<<setfill(' ')<<setw(8)<<name<<setfill(' ')<<setw(8)<<classes<<setfill(' ')<<setw(8)<<gender<<setfill(' ')<<setw(8)<<age;
    cout<<setfill(' ')<<setw(12)<<pro_score<<setfill(' ')<<setw(12)<<en_score<<setfill(' ')<<setw(12)<<program_score<<setfill(' ')<<setw(12)<<adma_score<<endl;
    }
    int get_pro_score()
    {
        return pro_score;
    }
    int get_program_score()
    {
        return program_score;
    }
    int get_en_score()
    {
        return en_score;
    }
    int get_adma_score()
    {
        return adma_score;
    }
    void file_input_big()
    {
        file>>sch_num>>name>>gender>>age>>classes>>pro_score>>en_score>>program_score>>adma_score;
    }
protected:
    int pro_score;
    int program_score;
    int adma_score;
    int en_score;
};

void show_main()
{
    cout<<"    **ѧ���ɼ�����ϵͳ**"<<endl;
    cout<<"    ����������������������������������������"<<endl;
    cout<<"    ��    1.�����¼    ��"<<endl;
    cout<<"    ��    2.ͳ�Ƽ�¼    ��"<<endl;
    cout<<"    ��    3.�����¼    ��"<<endl;
    cout<<"    ��    4.�����¼    ��"<<endl;
    cout<<"    ��    5.��¼����    ��"<<endl;
    cout<<"    ��    6.�˳�����    ��"<<endl;
    cout<<"    ��������벢�س����ɩ�"<<endl;
    cout<<"    ##By ETW,Copyright##"<<endl;
}

void show_add()
{
    cout<<"         **��Ӽ�¼**     "<<endl;
    cout<<"    ��������������������������������������������"<<endl;
    cout<<"    ��    1.���Сѧ��    ��"<<endl;
    cout<<"    ��    2.�����ѧ��    ��"<<endl;
    cout<<"    ��    3.��Ӵ�ѧ��    ��"<<endl;
    cout<<"    ��    4.������һ��    ��"<<endl;
    cout<<"    ����������벢�س����ɩ���"<<endl;
    cout<<"    ###By ETW,Copyright###"<<endl;
}

void show_manage()
{
    cout<<"         **�����¼**   "<<endl;
    cout<<"    ����������������������������������������"<<endl;
    cout<<"    ��    1.��Ӽ�¼    ��"<<endl;
    cout<<"    ��    2.��ѯ��¼    ��"<<endl;
    cout<<"    ��    3.������¼    ��"<<endl;
    cout<<"    ��    4.�༭��¼    ��"<<endl;
    cout<<"    ��    5.ɾ����¼    ��"<<endl;
    cout<<"    ��    6.������һ��  ��"<<endl;
    cout<<"    ��������벢�س����ɩ�"<<endl;
    cout<<"    ##By ETW,Copyright##"<<endl;
}

void show_find()
{
    cout<<"        **��ѯ��¼**    "<<endl;
    cout<<"    ����������������������������������������"<<endl;
    cout<<"    ��   1.��ѧ�Ų���   ��"<<endl;
    cout<<"    ��   2.����������   ��"<<endl;
    cout<<"    ��   3.������һ��   ��"<<endl;
    cout<<"    ��������벢�س����ɩ�"<<endl;
    cout<<"    ##By ETW,Copyright##"<<endl;
}

void show_output()
{
    cout<<"         **������¼**     "<<endl;
    cout<<"    ��������������������������������������������"<<endl;
    cout<<"    ��    1.����Сѧ��    ��"<<endl;
    cout<<"    ��    2.������ѧ��    ��"<<endl;
    cout<<"    ��    3.������ѧ��    ��"<<endl;
    cout<<"    ��    4.��������ѧ��  ��"<<endl;
    cout<<"    ��    5.������һ��    ��"<<endl;
    cout<<"    ����������벢�س����ɩ���"<<endl;
    cout<<"    ###By ETW,Copyright###"<<endl;
}

int input()
{
    int code;
    string str;
    cout<<"��������룺";
    cin>>str;
    code = string2int(str);
    return code;
}

void main_loop()
{
    show_main();
    while (1==1)
    {
        switch(input())
        {
        case 1:
            manage_loop();
            break;
        case 2:
            break;
        case 3:
            file_write();
            break;
        case 4:
            file_read();
            break;
        case 5:
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"���������������������룡\n";
            break;
        }
    }
}

void manage_loop()
{
    show_manage();
    while (1==1)
    {
        switch(input())
        {
        case 1:
            add_loop();
            break;
        case 2:
            find_loop();
            break;
        case 3:
            output_loop();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            main_loop();
        default:
            cout<<"���������������������룡\n";
        }
    }
}

void output_loop()
{
    show_output();
    while (1==1)
    {
        switch(input())
        {
        case 1:
            output_small();
            break;
        case 2:
            output_medium();
            break;
        case 3:
            output_big();
            break;
        case 4:
            output_all();
            break;
        case 5:
            manage_loop();
        default:
            cout<<"���������������������룡\n";
        }
    }
}

void add_loop()
{
    show_add();
    while (1==1)
    {
        switch(input())
        {
        case 1:
            add_smallstudent();
            cout<<"¼��ɹ���\n";
            break;
        case 2:
            add_mediumstudent();
            cout<<"¼��ɹ���\n";
            break;
        case 3:
            add_bigstudent();
            cout<<"¼��ɹ���\n";
            break;
        case 4:
            manage_loop();
            break;
        default:
            cout<<"���������������������룡\n";
        }
    }
}
void add_smallstudent()
{
    SmallStudent smallstudents_temp;
    smallstudents_temp.input_sch_num();
    smallstudents_temp.input_name();
    smallstudents_temp.input_gender();
    smallstudents_temp.input_age();
    smallstudents_temp.input_classes();
    smallstudents_temp.input_ch_score();
    smallstudents_temp.input_ma_score();
    smallstudents_temp.input_en_score();
    smallstudents.push_back(smallstudents_temp);
}
void add_mediumstudent()
{
    MediumStudent mediumstudents_temp;
    mediumstudents_temp.input_sch_num();
    mediumstudents_temp.input_name();
    mediumstudents_temp.input_age();
    mediumstudents_temp.input_gender();
    mediumstudents_temp.input_classes();
    mediumstudents_temp.input_ch_score();
    mediumstudents_temp.input_ma_score();
    mediumstudents_temp.input_en_score();
    mediumstudents_temp.input_gr_score();
    mediumstudents_temp.input_hi_score();
    mediumstudents.push_back(mediumstudents_temp);
}
void add_bigstudent()
{
    BigStudent bigstudents_temp;
    bigstudents_temp.input_sch_num();
    bigstudents_temp.input_name();
    bigstudents_temp.input_age();
    bigstudents_temp.input_gender();
    bigstudents_temp.input_classes();
    bigstudents_temp.input_pro_score();
    bigstudents_temp.input_program_score();
    bigstudents_temp.input_adma_score();
    bigstudents_temp.input_en_score();
    bigstudents.push_back(bigstudents_temp);
}

void find_loop()
{
    show_find();
    while (1==1)
    {
        switch(input())
        {
        case 1:
            {
            int a = find_num(input_num());
            if(a==-1)
            {
                cout<<"���޴��ˣ�\n";
                break;
            }
            cout<<"ѧ��        ����    �༶    �Ա�    ����    ���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�"<<endl;
            smallstudents[a].output_();
            break;
            }
        case 2:
            {
            int a = find_name(inputName());
            if(a==-1)
            {
                cout<<"���޴��ˣ�\n";
                break;
            }
            cout<<"ѧ��        ����    �༶    �Ա�    ����    ���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�"<<endl;
            smallstudents[a].output_();
            str = "";
            break;
            }
        case 3:
            manage_loop();
            break;
        default:
            cout<<"���������������������룡\n";
        }
    }
}

int find_num(string num)
{
    int a=0,b=0,c=0;
    {
        vector<SmallStudent>::iterator it;
        for(it=smallstudents.begin();it!=smallstudents.end();it++)
        {
            if((*it).get_num() == num)
            {
                return a;
                break;
            }
            a++;
        }
    }
    {
        vector<MediumStudent>::iterator it;
        for(it=mediumstudents.begin();it!=mediumstudents.end();it++)
        {
            if((*it).get_num() == num)
            {
                return b;
                break;
            }
            b++;
        }
    }
    {
        vector<BigStudent>::iterator it;
        for(it=bigstudents.begin();it!=bigstudents.end();it++)
        {
            if((*it).get_num() == num)
            {
                return c;
                break;
            }
            c++;
        }
    }
    if(a==0&&b==0&&c==0)
        return -1;
}

int find_name(string nam)
{
    int a=0,b=0,c=0;
    {
        vector<SmallStudent>::iterator it;
        for(it=smallstudents.begin();it!=smallstudents.end();it++)
        {
            if((*it).get_name() == nam)
            {
                return a;
            }
            a++;
        }
    }
    {
        vector<MediumStudent>::iterator it;
        for(it=mediumstudents.begin();it!=mediumstudents.end();it++)
        {
            if((*it).get_name() == nam)
            {
                return b;
            }
            b++;
        }
    }
    {
        vector<BigStudent>::iterator it;
        for(it=bigstudents.begin();it!=bigstudents.end();it++)
        {
            if((*it).get_name() == nam)
            {
                return c;
            }
            c++;
        }
    }
    if(a==0&&b==0&&c==0)
        return -1;
}

string input_num()
{
    cout<<"������ѧ�ţ�";
    cin>>str;
    for(int i=0;sizeof(str);i++)
    {
        if(str[i]<48||str[i]>58)
        {
            cout<<"���������������������룡"<<endl;
            input_num();
        }
    }
    return str;
}

string inputName()
{
    string str;
    cout<<"������������";
    cin>>str;
    return str;
}

void output_small()
{
    cout<<"ѧ��        ����    �༶    �Ա�    ����    ���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�"<<endl;
    vector<SmallStudent>::iterator it;
    for(it=smallstudents.begin();it!=smallstudents.end();it++)
    {
        (*it).output_();
    }
}

void output_medium()
{
    cout<<"ѧ��        ����    �༶    �Ա�    ����    ���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�    ����ɼ�    ��ʷ�ɼ�"<<endl;
    vector<MediumStudent>::iterator it;
    for(it=mediumstudents.begin();it!=mediumstudents.end();it++)
    {
        (*it).output_();
    }
}

void output_big()
{
    cout<<"ѧ��        ����    �༶    �Ա�    ����    רҵ�ɼ�    Ӣ��ɼ�    �������    �ߵ���ѧ"<<endl;
    vector<BigStudent>::iterator it;
    for(it=bigstudents.begin();it!=bigstudents.end();it++)
    {
        (*it).output_();
    }
}

void output_all()
{
    cout<<"ѧ��        ����    �༶    �Ա�    ����"<<endl;
        {
        vector<SmallStudent>::iterator it;
        for(it=smallstudents.begin();it!=smallstudents.end();it++)
        {
            (*it).output();
        }
    }
    {
        vector<MediumStudent>::iterator it;
        for(it=mediumstudents.begin();it!=mediumstudents.end();it++)
        {
            (*it).output();
        }
    }
    {
        vector<BigStudent>::iterator it;
        for(it=bigstudents.begin();it!=bigstudents.end();it++)
        {
            (*it).output();
        }
    }
}

void file_write()
{
    file.open("F:\\data1.dat", ios::out|ios::binary);
    {
        vector<SmallStudent>::iterator it;
        for(it=smallstudents.begin();it!=smallstudents.end();it++)
        {
            file<<"\n"<<(*it).get_num()<<"\n"<<(*it).get_name()<<"\n"<<(*it).get_gender()<<"\n"<<(*it).get_age()<<"\n"<<(*it).get_classes()<<"\n"<<(*it).get_ch_score()<<"\n"<<(*it).get_ma_score()<<"\n"<<(*it).get_en_score();
        }
    }
    file.close();
    file.open("F:\\data2.dat", ios::out|ios::binary);
    {
        vector<MediumStudent>::iterator it;
        for(it=mediumstudents.begin();it!=mediumstudents.end();it++)
        {
            file<<"\n"<<(*it).get_num()<<"\n"<<(*it).get_name()<<"\n"<<(*it).get_gender()<<"\n"<<(*it).get_age()<<"\n"<<(*it).get_classes()<<"\n"<<(*it).get_ch_score()<<"\n"<<(*it).get_ma_score()<<"\n"<<(*it).get_en_score()<<"\n"
            <<(*it).get_gr_score()<<"\n"<<(*it).get_hi_score();
        }
    }
    file.close();
    file.open("F:\\data3.dat", ios::out|ios::binary);
    {
        vector<BigStudent>::iterator it;
        for(it=bigstudents.begin();it!=bigstudents.end();it++)
        {
            file<<"\n"<<(*it).get_num()<<"\n"<<(*it).get_name()<<"\n"<<(*it).get_gender()<<"\n"<<(*it).get_age()<<"\n"<<(*it).get_classes()<<"\n"<<(*it).get_pro_score()<<"\n"<<(*it).get_en_score()<<"\n"<<(*it).get_program_score()<<"\n"<<(*it).get_adma_score();
        }
    }
    file.close();
    cout<<"����ɹ���"<<endl;
}

void file_read()
{
    file.open("F:\\data1.dat", ios::in|ios::binary);
    do{
        SmallStudent smallstudents_temp;
        smallstudents_temp.file_input_small();
        smallstudents.push_back(smallstudents_temp);
    }while(!file.eof());
    file.close();
    file.open("F:\\data2.dat", ios::in|ios::binary);
    do{
        MediumStudent mediumstudents_temp;
        mediumstudents_temp.file_input_medium();
        mediumstudents.push_back(mediumstudents_temp);
    }while(!file.eof());
    file.close();
    file.open("F:\\data3.dat", ios::in|ios::binary);
    do{
        BigStudent bigstudents_temp;
        bigstudents_temp.file_input_big();
        bigstudents.push_back(bigstudents_temp);
    }while(!file.eof());
    file.close();
    cout<<"����ɹ���"<<endl;
}














