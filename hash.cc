#include "hash.h"

/** fill **/

template <class T>
Linked_list<T>::Linked_list()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
Linked_list<T>::~Linked_list()
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        //cout << "delete " << temp->data << endl;
        node<T>* temp1 = temp->next_node;
        delete temp;
        temp = temp1;
        size--;
    }
}

template <class T>
void Linked_list<T>::addNode(T data_in)
{
    node<T>* newnode = new node<T>(data_in, NULL);
    //cout << "adding "<< newnode->data << endl;
    if (size == 0)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next_node = newnode;
        newnode->next_node = NULL;
        tail=newnode;
    }
    size++;
    //printf("current size : %d\n", size);
}

HashTable::HashTable(int m, int t)
{
    table_size = t;
    max_size = m;
    //student_id = (Linked_list<int>*)malloc(sizeof(Linked_list<int>)*table_size);
    //grade = (Linked_list<char>*)malloc(sizeof(Linked_list<char>)*table_size);
    //project_score = (Linked_list<double>*)malloc(sizeof(Linked_list<double>)*table_size);
    student_id = new Linked_list<int>[t];
    grade = new Linked_list<char>[t];
    project_score = new Linked_list<double>[t];
}

HashTable::~HashTable()
{
    /*for (int i = 0; i < table_size; i++)
    {
        delete &student_id[i];
        delete &grade[i];
        delete &project_score[i];
    }*/
    /*free(student_id);
    free(grade);
    free(project_score);*/
    delete[] student_id;
    delete[] grade;
    delete[] project_score;
}

void HashTable::insertItems(int k, int s, char g, double p)
{
    int bucket = k % table_size;
    if (max_size == student_id[bucket].get_size())
    {
        printf("Delete data that exceeds max size.\n");
        printf("Data: %d, %c, %f\n", s, g, p);
        return;
    }
    //printf("\nadding to bucket %d\n", bucket);
    student_id[bucket].addNode(s);
    grade[bucket].addNode(g);
    project_score[bucket].addNode(p);
}

void HashTable::print_hash_map()
{
    for (int i = 0; i < table_size; i++)
    {
        node<int>* tmp1 = student_id[i].get_head();
        node<char>* tmp2 = grade[i].get_head();
        node<double>* tmp3 = project_score[i].get_head();
        cout << i << " -> ";
        while (tmp1 != NULL)
        {
            cout << tmp1->data << ", " << tmp2-> data << ", " << tmp3->data << " -> ";
            tmp1 = tmp1->next_node;
            tmp2 = tmp2->next_node;
            tmp3 = tmp3->next_node;
        }
        cout << endl;
    }
}



