#include<iostream>
using namespace std;

class Dictionary {
    private:
    class Node {
        public:
        string data; //�ܾ ������ ����
        Node* link; //���� ����� �ּҸ� ������ ������
        Node(string word) { data = word; link = NULL;}; //word�� data�� ������ Node�� �����ϴ� ������
    };
    Node* first; //ù ��° ��带 ����ų ������

public:
    Dictionary(string word); //������
    void Find(string word); //word�� �� ��° ��ġ�� �ִ� �� ���, ������ ���ٰ� ���
    void Insert(string word); //�ܾ� ������ ��ġ�� ����(���ĺ� ��)
    void Delete(string word); //word�� ����Ʈ���� ����, ���� ��쵵 ����ó�� �ؾ� ��
    void Display();
};

Dictionary::Dictionary(string word) {
    first = new Node(word); //�Ű������� ���� word�� data�� ������ Node�� ����, first�� ����Ű�� ��
}

void Dictionary::Find(string word) { //�� ��°? ������ ����
    if (!first) //LL�� �� ���
    {
        cout << "Empty Linkes List" << endl; //��� ���
        return; //�Լ� ����
    }

    Node* tmp = first; //LL�� ó������ ������ �� ��带 Ž���� ������
    int count = 1; //ã�� word�� �� ��° ������� ������ ����

    while (1) //tmp�� ������ ������ ����Ų �� �ݺ� ����
    {
        if (!tmp) //LL�� �� ���� ������ ���
        {
            cout << '\"' << word << "\" isn't exist in this Dictionary" << endl; //��� ���
            return; //�Լ� ����
        }
        else if (tmp->data == word) //tmp�� ã�� word�� ���� ����� ���
        {
            cout << "The sequence of \"" << word << "\" : " << count << endl; //�� ��° ������� ���
            return; //�Լ� ����
        }

        tmp = tmp->link; //���� ��带 ����Ŵ
        count++;
    }
}

void Dictionary::Insert(string word) {
    Node* node = new Node(word); //word�� data�� ���� ������ ��� ���� 

    if (!first) //LL�� ����ִ� ���
    {
        first = node; //first�� ������ ��带 ����Ŵ
        return; //�Լ� ����
    }
    else if (first->data > word) //������ ��尡 ���Ե� �ڸ��� �� ���� ���
    {
          node->link = first; //������ ����� link�� ������ first ��带 ����Ŵ
          first = node; //first�� ������ ��带 ����Ŵ
          return; //�Լ� ����
    }

    //LL�� �߰��̳� �� ���� �ܾ ���ԵǴ� ���
    Node* tmp = first; //���Ե� ������ ��ġ�� ���� ��带 ã�� Node ������
    Node* prev = NULL; //���Ե� ������ ��ġ�� ���� ��带 ã�� Node ������

    while (1)
    {
        prev = tmp; //���� ��带 ����Ŵ
        tmp = tmp->link; //���� ��带 ����Ŵ

        if (!tmp) //LL�� �� ���� ������ ���
            break; //�ݺ� ����
        else if (tmp->data >= word) //prev�� tmp ���̰� ���Ե� ������ ��ġ�� ���
            break; //�ݺ� ����
    }

    node->link = tmp; //������ ��尡 tmp�� ����Ŵ (���Ե� ��ġ�� �� ���� ��� NULL�� ����Ŵ)
    prev->link = node; //prev�� ������ ��带 ����Ŵ
}

void Dictionary::Delete(string word) {
    if (!first) //LL�� �� ���
    {
        cout << "Empty Linkes List" << endl; //��� ���
        return; //�Լ� ����
    }

    Node* tmp = first; //������ word�� data�� ���� ��带 ã�� ������
    Node* prev = NULL; //tmp ������ ��带 ã�� ������
    while (1)
    {
        if (!tmp) //LL�� �� ���� ������ ���
            break; //�ݺ� ����
        else if (tmp->data == word) //tmp�� ������ word�� ���� ��带 ����ų ���
            break; //�ݺ� ����
            
        prev = tmp; //���� ��带 ����Ŵ
        tmp = tmp->link; //���� ��带 ����Ŵ
    }

    if (!tmp) //������ word�� ���� ��尡 ���� ���
    {
         cout << "�����Ϸ��� Data�� �����ϴ�" << endl; //��� ���
    }
    else if (tmp == first) //ù ��° ��尡 ������ word�� ���� ���
    {
        first = first->link; //first�� ���� �� ��° ��带 ����Ŵ
        tmp->link = NULL; //��ȯ�ϱ� �� link �ʱ�ȭ
        delete tmp; //������ ����� �޸� ��ȯ
    }
    else //������ word�� ���� ��尡 ������ ����̰ų� �� ��� ������ ���
    {
        prev->link = tmp->link; //prev�� ���� ��尡 ����Ű�� ��带 ����Ŵ(������ ����� ��� NULL�� ����Ŵ)
        tmp->link = NULL; //��ȯ�ϱ� �� link �ʱ�ȭ
        delete tmp; //������ ����� �޸� ��ȯ
    }
}

void Dictionary::Display() {
    if (!first) //LL�� �� ���
    {
        cout << "Empty Linkes List" << endl; //��� ���
        return; //�Լ� ����
    }

    Node* tmp = first; //LL�� ó������ ������ �� ��带 Ž���� ������

    while (tmp != NULL) //tmp�� ������ ������ ����Ų �� �ݺ� ����
    {
        cout << tmp->data << '\t'; //�ش� ����� data ���
        tmp = tmp->link; //���� ��带 ����Ŵ
    }
    cout << endl;
}

int main() {
    Dictionary Dt("ABC");
    int input = 1;
    string word;

    while (input) {
        cout << "(1)Insert    (2)Delete    (3)Display    (4)Find    (0)END" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert : ";
            cin >> word;
            Dt.Insert(word);
        }
        else if (input == 2) {
            cout << "Word to Delete : ";
            cin >> word;
            Dt.Delete(word);
        }
        else if (input == 3) {
            Dt.Display();
        }
        else if (input == 4) {
            cout << "Word to Find : ";
            cin >> word;
            Dt.Find(word);
        }
    } 
}
