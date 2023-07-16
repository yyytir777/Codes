#include <iostream>
using namespace std;

class Polynomial
{
private:
    class Node
    {
    public:
        float coef; //���
        int exp; //����
        Node* link; //���� ��带 ����ų ������
        Node(float c, int e = 0) { coef = c; exp = e; } //Node ������
    };
    Node* first;
public:
    Polynomial() { first = NULL; } //Polynomial ������
    void Get_Polynomial(); //���׽��� �Է¹��� �Լ�
    void Insert(float c, int e); //���c�� ����e�� ���� ���� ���׽Ŀ� �߰�
    Polynomial operator +(const Polynomial& b); //���׽� ���� ��� ��ȯ
    Polynomial operator -(const Polynomial& b); //���׽� ���� ��� ��ȯ
    void Print(); //���׽��� ������������ ���
};

void Polynomial::Get_Polynomial()
{
    float C; //����� �Է¹��� ����
    int E; //������ �Է¹��� ����
    
    cout << "���׽� ���� ���� (����� 0�� �Է��ϸ� ������ �ߴ��մϴ�)" << endl;

    while (1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        cout << "�߰��� ���� ���(�Ǽ�)�� ����(����)�� �Է��ϼ��� : ";
        cin >> C >> E; //����� ���� �Է¹���
        
        if (C == 0) //����� 0�� �Է¹�����
            break; //�Լ� ���� (���׽� ���� �ߴ�)
        
        Insert(C,E); //���C�� ����E�� ���� ���� �߰�
    }
}

void Polynomial::Insert(float c, int e)
{
    Node* tmp = first; //�� ��带 ���� ����� �ߺ��� ���� ã�� Node ������
    while (tmp) //tmp�� ������ ����� link�� NULL�� �����ϸ� �ݺ� ����
    {
        if (e == tmp->exp) //������ ����� ������ ���� ������ ���� ���� ������ ���
        {
            cout << "���� ������ ���� ���� �̹� �����մϴ�" << endl; //��� ���
            return; //�Լ� ����
        }
        tmp = tmp->link; //���� ��带 ����Ŵ
    }

    Node* node = new Node(c,e); //c�� e�� ����� ������ ���� ��� ����

    if (!first) //���׽��� ù ��° ��尡 ������ ��
    {
        first = node; //first�� ������ ��尡 ����Ŵ
        return; //�Լ� ����
    }

    //�� ��° �̻� ���� ������ ��

    if (e > first->exp) //������ ��尡 �ְ������̶� ���Ե� �ڸ��� �� ���� ���
    {
          node->link = first; //������ ����� link�� ������ first ��带 ����Ŵ
          first = node; //first�� ������ ��带 ����Ŵ
          return; //�Լ� ����
    }

    //���׽��� �߰��̳� �� ���� ���� ���ԵǴ� ���
    tmp = first; //���Ե� ������ ��ġ�� ���� ��带 ã�� Node ������
    Node* prev = NULL; //���Ե� ������ ��ġ�� ���� ��带 ã�� Node ������

    while (1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        prev = tmp; //���� ��带 ����Ŵ
        tmp = tmp->link; //���� ��带 ����Ŵ

        if (!tmp) //LL�� �� ���� ������ ���
            break; //�ݺ� ����
        else if (prev->exp > e  && e > tmp->exp) //prev�� tmp ���̰� ���Ե� ������ ��ġ�� ���
            break; //�ݺ� ����
    }

    node->link = tmp; //������ ��尡 tmp�� ����Ŵ (���Ե� ��ġ�� �� ���� ��� NULL�� ����Ŵ)
    prev->link = node; //prev�� ������ ��带 ����Ŵ
}

Polynomial Polynomial::operator +(const Polynomial& b)
{
    Polynomial result; //�� ���׽��� ���� ������ ���׽�
    Node* ai = this->first; //ù ��° ���׽��� ��带 ����ų ������
    Node* bi = b.first; //�� ��° ���׽��� ��带 ����ų ������
    
    while (1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        if (!ai) //ai�� NULL�� ��� (���׽� a�� �� �̻� ����� ���� ���� ���)
        {
            while(bi) //bi�� NULL�� �����ϸ� �ݺ� ���� (���׽� b���� �� �̻� ����� ���� ���� ��)
            {
                result.Insert(bi->coef, bi->exp); //bi�� ����Ű�� ���� �׷��� result�� �߰�
                bi = bi->link; //���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }
        else if (!bi) //bi�� NULL�� ��� (���׽� b�� �� �̻� ����� ���� ���� ���)
        {
            while(ai) //ai�� NULL�� �����ϸ� �ݺ� ���� (���׽� a���� �� �̻� ����� ���� ���� ��)
            {
                result.Insert(ai->coef, ai->exp); //ai�� ����Ű�� ���� �׷��� result�� �߰�
                ai = ai->link; //���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }


        if (ai->exp > bi->exp) //ai�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(ai->coef, ai->exp); //ai�� ����Ű�� ���� �׷��� result�� �߰�
            ai = ai->link; //���� ���� ����Ŵ
        }
        else if (ai->exp < bi->exp) //bi�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(bi->coef, bi->exp); //bi�� ����Ű�� ���� �׷��� result�� �߰�
            bi = bi->link; //���� ���� ����Ŵ
        }
        else //ai�� bi�� ����Ű�� �� ���� ������ ���� ���
        {
            if (ai->coef + bi->coef) //�� ���� ����� ���� 0�� �ƴ� ���
                result.Insert(ai->coef + bi->coef, ai->exp); //�� ���� ����� ��, �� �װ� ���� ������ ���� ���� result�� �߰�
            
            ai = ai->link; //���� ���� ����Ŵ
            bi = bi->link; //���� ���� ����Ŵ
            
        }
    }

    return result; //������ �Ϸ�� ���׽��� return
}

Polynomial Polynomial::operator -(const Polynomial& b)
{
    Polynomial result; //�� ���׽��� ���� ������ ���׽�
    Node* ai = this->first; //ù ��° ���׽��� ��带 ����ų ������
    Node* bi = b.first; //�� ��° ���׽��� ��带 ����ų ������
    
    while (1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        if (!ai) //ai�� NULL�� ��� (���׽� a�� �� �̻� ����� ���� ���� ���)
        {
            while(bi) //bi�� NULL�� �����ϸ� �ݺ� ���� (���׽� b���� �� �̻� ����� ���� ���� ��)
            {
                result.Insert(-(bi->coef), bi->exp); //bi�� ����Ű�� ���� ����� ��ȣ�� �ٲ� �� result�� �߰�
                bi = bi->link; //���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }
        else if (!bi) //bi�� NULL�� ��� (���׽� b�� �� �̻� ����� ���� ���� ���)
        {
            while(ai) //ai�� NULL�� �����ϸ� �ݺ� ���� (���׽� a���� �� �̻� ����� ���� ���� ��)
            {
                result.Insert(ai->coef, ai->exp); //ai�� ����Ű�� ���� �׷��� result�� �߰�
                ai = ai->link; //���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }


        if (ai->exp > bi->exp) //ai�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(ai->coef, ai->exp); //ai�� ����Ű�� ���� �׷��� result�� �߰�
            ai = ai->link; //���� ���� ����Ŵ
        }
        else if (ai->exp < bi->exp) //bi�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(-(bi->coef), bi->exp); //bi�� ����Ű�� ���� ����� ��ȣ�� �ٲ� �� result�� �߰�
            bi = bi->link; //���� ���� ����Ŵ
        }
        else //ai�� bi�� ����Ű�� �� ���� ������ ���� ���
        {
            if (ai->coef - bi->coef) //�� ���� ����� ���� 0�� �ƴ� ���
                result.Insert(ai->coef - bi->coef, ai->exp); //�� ���� ����� ��, �� �װ� ���� ������ ���� ���� result�� �߰�
            
            ai = ai->link; //���� ���� ����Ŵ
            bi = bi->link; //���� ���� ����Ŵ
            
        }
    }

    return result; //������ �Ϸ�� ���׽��� return
}

void Polynomial::Print()
{
    if (!first) //LL�� �� ���
    {
        cout << "Empty Linkes List" << endl; //��� ���
        return; //�Լ� ����
    }

    Node* tmp = first; //LL�� ó������ ������ �� ��带 Ž���� ������

    while (tmp != NULL) //tmp�� ������ ������ ����Ų �� �ݺ� ����
    {
        if (tmp->exp == 0) //������ 0�� ������� ���
        {
            if (tmp->coef > 0) //����� ����� ���
                cout << '+'; //'+' ���
            cout << tmp->coef; //���(���)�� ���
            break; //������ ���� ��µǾ����Ƿ� �ݺ� ����
        }

        //������� �ƴ� ���

        if (tmp->coef > 0) //����� ����� ���
            cout << '+' << tmp->coef << "x^"; //'+'�� ��� ���
        else if (tmp->coef < 0) //����� ������ ���
            cout << tmp->coef << "x^"; //����� ���
            
        cout << tmp->exp; //���� ���
        tmp = tmp->link; //���� ��带 ����Ŵ
    }
    cout << endl;
}

int main()
{
    Polynomial A, B;

    cout << "[A] ";    
    A.Get_Polynomial();
    cout << "[B] ";
    B.Get_Polynomial();

    cout << "[A] = ";
    A.Print();
    cout << "[B] = ";
    B.Print();

    Polynomial C = A + B;
    Polynomial D = A - B;

    cout << "[A] + [B] = ";
    C.Print();
    cout << "[A] - [B] = ";
    D.Print();

    return 0;   
}