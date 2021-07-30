#include <iostream>
using namespace std;
enum Status
{
    landed,
    circling,
    permission,
    onTheWay
};

class Airplane
{
public:
    int id;
    string name;
    Status c;
    Airplane(int id, string name, Status c)
    {
        this->id = id;
        this->name = name;
        this->c = c;
    }
    void setStatus(Status c)
    {
        this->c = c;
    }
    void display()
    {
        // cout << "ID: " << id << endl;
        // cout << "Name: " << name << endl;
        cout << name << endl;
        // cout << "Status: " << c << endl;
    }
};

class Node
{
public:
    Airplane *data;
    Node *next;
    Node(Airplane *data)
    {
        this->data = data;
        next = NULL;
    }
};

class Singly_Linked_List
{
    Node *head;

public:
    Singly_Linked_List()
    {
        head = NULL;
    }
    void insert_Start(Airplane *data)
    {
        Node *new_Node = new Node(data);
        if (head == NULL)
        {
            head = new_Node;
        }
        else
        {
            new_Node->next = head;
            head = new_Node;
        }
    }
    void insert_Last(Airplane *data)
    {
        Node *new_Node = new Node(data);
        if (head == NULL)
        {
            head = new_Node;
        }
        else
        {

            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_Node;
        }
    }

    Airplane *get_Airplane(int i)
    {
        Node *temp = head;
        for (int j = 1; j < i; j++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void delete_Start()
    {
        if (head != NULL)
        {
            Node *todelete = head;
            head = head->next;
            delete todelete;
        }
    }
    void delete_Last()
    {
        if (head != NULL)
        {
            Node *cur = head;
            Node *per = cur;
            while (cur->next != NULL)
            {
                per = cur;
                cur = cur->next;
            }
            per->next = NULL;
            delete cur;
        }
    }
    int getSize()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void changeStatus(Airplane *airplane, Status c)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == airplane)
            {
                temp->data->setStatus(c);
            }
            temp = temp->next;
        }
    }
    Airplane *search(int id)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data->id == id)
            {
                return temp->data;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp->data->display();
            cout << endl;
            temp = temp->next;
        }
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        //cout << "List is created.\n\n" << endl;
    }

    void enQueue(Airplane *data)
    {
        Node *new_Node = new Node(data);
        if (rear == NULL)
        {
            rear = new_Node;
            front = new_Node;
        }
        else
        {
            rear->next = new_Node;
            // rear = rear->next;
            rear = new_Node;
        }
    }

    Airplane *deQueue()
    {
        Airplane *a = NULL;
        if (front != NULL)
        {
            Node *todelete = front;
            front = front->next;
            a = todelete->data;
            delete todelete;
            // return a;
        }
        if (front == NULL) {
            rear = NULL;
        }
        return a;
    }

    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            temp->data->display();
            temp = temp->next;
        }
    }
};

int main()
{
    Singly_Linked_List SLL;
    Airplane *airplane;
    SLL.insert_Last(new Airplane(12, "Airplane1", landed));
    SLL.insert_Last(new Airplane(13, "Airplane2", circling));
    SLL.insert_Last(new Airplane(14, "Airplane3", permission));
    SLL.insert_Last(new Airplane(15, "Airplane4", onTheWay));
    Queue Landed, Circling, Permission, OnTheWay;
    for (int i = 1; i <= SLL.getSize(); i++)
    {
        airplane = SLL.get_Airplane(i);
        if (airplane->c == landed)
        {
            Landed.enQueue(airplane);
        }
        else if (airplane->c == circling)
        {
            Circling.enQueue(airplane);
        }
        else if (airplane->c == permission)
        {
            Permission.enQueue(airplane);
        }
        else if (airplane->c == onTheWay)
        {
            OnTheWay.enQueue(airplane);
        }
    }
    //SLL.display();
    char ch;
    do
    {
        cout << "\n\t\t1. to add a landed airplane.";
        cout << "\n\t\t2. to grant permission for landing.";
        cout << "\n\t\t3. to add a circling airplane.";
        cout << "\n\t\t4. to add a onTheWay airplane.";
        cout << "\n\t\t5. to display queues.";
        cout << "\n\t\t6. to exit.\n\n";
        cin >> ch;
        if (ch == '1')
        {
            airplane = Permission.deQueue();
            cout << airplane->name << " is landed." << endl;
            SLL.changeStatus(airplane, landed);
            Landed.enQueue(airplane);
            system("pause");
        }
        else if (ch == '2')
        {
            airplane = Circling.deQueue();
            cout << airplane->name << " is granted permission to land." << endl;
            SLL.changeStatus(airplane, permission);
            if(airplane->c == permission) {
                // cout << "Status changed to permission";
            Permission.enQueue(airplane);
            } else {
                // cout << "Permission not granted some error";
            }
            system("pause");
        }
        else if (ch == '3')
        {
            airplane = OnTheWay.deQueue();
            cout << airplane->name << " is added to circling queue." << endl;
            SLL.changeStatus(airplane, circling);
            Circling.enQueue(airplane);
            system("pause");
        }
        else if (ch == '4')
        {
            airplane = Landed.deQueue();
            cout << airplane->name << " is now on the on the way." << endl;
            SLL.changeStatus(airplane, onTheWay);
            OnTheWay.enQueue(airplane);
            system("pause");
        }
        else if (ch == '5')
        {
            cout << "\nLanded queue.\n";
            Landed.display();
            cout << "\nCircling queue.\n";
            Circling.display();
            cout << "\nPermission queue.\n";
            Permission.display();
            cout << "\nOnTheWay queue.\n";
            OnTheWay.display();
            system("pause");
        }
        system("cls");
    } while (ch != '6');
    //SLL.display();

    return 0;
}
