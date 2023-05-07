//
// Created by NUC on 2023/5/4.
//

#include<string>
#include<iostream>

using namespace std; // ���Ǹ����õ�ϰ��

// ����ÿ���������: ��Ϊ��׼
class CPU{
public:
    virtual void calculate() = 0;
};

// �Կ�: GPU
class VideoCard{
public:
    virtual void display() = 0;
};
// �ڴ�
class Memory{
public:
    virtual void storage() = 0;
};

// ������:
class Computer{
public:
    // ���캯�������������ָ��.
    Computer(CPU *cpu, VideoCard *videoCard, Memory *memory){ // ��̬�ĸ���, �����ָ��.  ��������������Ķ���
        this->cpu = cpu; // ���ò�ͬ������Ķ���ĺ���.
        this->videoCard = videoCard;
        this->memory = memory;
    }

    ~Computer(){ // �ṩһ����������, �ͷ������������
        cout << " ~Computer()" << endl;
        if (this->cpu){
            delete this->cpu;
            this->cpu = NULL;
        }
        if (this->videoCard){
            delete this->videoCard;
            this->videoCard = NULL;
        }
        if (this->memory){
            delete this->memory;
            this->memory = NULL;
        }
    }

    void work(){ // �����ĺ���.
        this->cpu->calculate();
        this->videoCard->display();
        this->memory->storage();
    }


private:
    CPU* cpu = NULL; // CPU�����ָ��
    VideoCard *videoCard = NULL;
    Memory *memory = NULL;
};

// ��ͬ���Գ���ʵ�ֵ����:
class IntelCPU: public CPU{
public:
    void calculate(){
        cout << "intel��cpu��ʼ������" << endl;
    }
};

class NvidiaGPU: public VideoCard{
public:
    void display(){
        cout << "Nvidia��GPU��ʼ������" << endl;
    }
};

class LenovoMemory: public Memory{
public:
    void storage(){
        cout << "Lenovo���ڴ�����ʼ������" << endl;
    }
};

void test01(){
    CPU *cpu = new IntelCPU(); // ����ָ������������
    VideoCard *gpu = new NvidiaGPU();
    Memory *memory = new LenovoMemory();

    Computer *computer = new Computer(cpu, gpu, memory);
    computer->work();

    delete computer; // ִ����������.
}




int main() {
    test01();






    return 0;




}

