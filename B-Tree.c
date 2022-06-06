#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct date
{
	int day;
	int month;
	int yr;
};

typedef struct book_tag
{
	char Name[50];
	char Sub[50];
	char Author[50];
	char Acc_No[20];
	char print_type[15];
	int yop;
	char status[10];
	struct date issued,renew;
}book;

typedef struct member_tag
{
	char Name[50];
	char Dep[50];
	char Status[20];
	char ID[20];
	int nob;
	int notimes_finepaid;
	book iss_books[5];
}member;

#define MAX 3
#define MIN 2


// B tree node for books
typedef struct btreeNode_tagBook
{
	book data[MAX+1];
	int count;
	struct btreeNode_tagBook *link[MAX+1]; 
}btreeNode_book;

// B tree Node of Member
typedef struct btreeNode_tagMem
{
	member data[MAX+1];
	int count;
	struct btreeNode_tagMem *link[MAX+1]; 
}btreeNode_mem;

// Declarations of functions

btreeNode_book* createNode_book(book item, btreeNode_book* child, btreeNode_book* root);
void insertValue_book(book item, int pos, btreeNode_book* node, btreeNode_book* child); 
void splitNode_book(book item, book *pval, int pos, btreeNode_book* node, btreeNode_book* child, btreeNode_book** newNode); 
int compare_book(book item1,book item2);
int setNodeValue_book(book item, book* pval, btreeNode_book* node, btreeNode_book** child);
btreeNode_book* insert_book(book item,btreeNode_book* root); 
void traversal_book(btreeNode_book* myNode);
btreeNode_mem* createNode_mem(member item, btreeNode_mem *child, btreeNode_mem* root);
void insertValue_mem(member item, int pos, btreeNode_mem *node, btreeNode_mem *child);
void splitNode_mem(member item, member *pval, int pos, btreeNode_mem *node, btreeNode_mem *child, btreeNode_mem **newNode);
int compare_member(member mem1, member mem2);
int setNodeValue_mem(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child);
btreeNode_mem* insert_mem(member item,btreeNode_mem* root);
int setNodeValue_mem_fine(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child);
btreeNode_mem* insert_mem_fine(member item,btreeNode_mem* root);
void traversal_mem_fine(btreeNode_mem* myNode);
int compare_member_nob(member mem1, member mem2);
int setNodeValue_mem_nob(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child);
btreeNode_mem* insert_mem_nob(member item,btreeNode_mem* root);
void traversal_mem_nob(btreeNode_mem* myNode);
int searchBook_name(btreeNode_book* myNode,char* name);
void searchBook_Author(btreeNode_book* myNode,char* Author);
void search_AccNo_stu(btreeNode_book** books, char* Acc, book* bok);
void search_AccNo_fac(btreeNode_book** books, char* Acc, book* bok);
btreeNode_mem* ADD_Student(btreeNode_mem* stu, btreeNode_mem** fine, btreeNode_mem** stu_nob, btreeNode_book** books);
btreeNode_mem* ADD_Faculty(btreeNode_mem* fac, btreeNode_mem** fine, btreeNode_mem** fac_nob, btreeNode_book** books);
int Max_No_of_books(btreeNode_mem* myNode);
void Max_books_mem(btreeNode_mem* myNode,int max);
btreeNode_book* INSERT_book(btreeNode_book* books);
void print_renew(btreeNode_book** books,char* Acc);
book Renew_date_stu(book bok);
book Renew_date_fac(book bok);
int Fine(member mem,int YEAR,int MON,int DAY);
int Max_fine(btreeNode_mem* myNode,int YEAR,int MON,int DAY);
void print_fine(btreeNode_mem** mem,char* ID,int YEAR,int MON,int DAY);
void Max_fine_mem(btreeNode_mem* myNode,int max,int YEAR,int MON,int DAY);
void search_stu_ID(btreeNode_mem** stu, char* ID, btreeNode_book** books);
btreeNode_mem* Issue_book_stu(btreeNode_mem* stu, btreeNode_book** books );
void search_fac_ID(btreeNode_mem** fac, char* ID, btreeNode_book** books);
btreeNode_mem* Issue_book_fac(btreeNode_mem* fac, btreeNode_book** books );
void merge(btreeNode_mem* stu_nob, btreeNode_mem** fac_nob);
void Assign_book_stu(btreeNode_book** books, char* Acc, book* bok,int YEAR, int MON, int DAY);
void Assign_book_fac(btreeNode_book** books, char* Acc, book* bok,int YEAR, int MON, int DAY);

// Starting of Main 
int main()
{
	btreeNode_book* books = NULL;
	btreeNode_mem* stu = NULL;
	btreeNode_mem* fac =  NULL;
	btreeNode_mem* fine = NULL;
	btreeNode_mem* stu_nob = NULL;
	btreeNode_mem* fac_nob = NULL;
	
	book bok1,bok2,bok3,bok4,bok5,bok6,bok7,bok8,bok9,bok10;
	
	strcpy(bok1.Name,"C Programming");strcpy(bok1.Sub,"Coding");strcpy(bok1.Author,"Yashwanth");strcpy(bok1.Acc_No,"1");strcpy(bok1.status,"available");
	strcpy(bok1.print_type,"NewBook");bok1.yop = 2015;
	books = insert_book(bok1,books); // insert book1
	
	strcpy(bok2.Name,"JAVA");strcpy(bok2.Sub,"Coding");strcpy(bok2.Author,"Vijay");strcpy(bok2.Acc_No,"2");strcpy(bok2.status,"available");
	strcpy(bok2.print_type,"NewBook");bok2.yop = 2014;
	books = insert_book(bok2,books); // insert book2
	
	strcpy(bok3.Name,"C Programming");strcpy(bok3.Sub,"Coding");strcpy(bok3.Author,"Yashwanth");strcpy(bok3.Acc_No,"3");strcpy(bok3.status,"available");
	strcpy(bok3.print_type,"NewPrint");bok3.yop = 2016;
	books = insert_book(bok3,books); // insert book3
	
	strcpy(bok4.Name,"Avadhanulu");strcpy(bok4.Sub,"Physics");strcpy(bok4.Author,"Avadhan");strcpy(bok4.Acc_No,"4");strcpy(bok4.status,"available");
	strcpy(bok4.print_type,"NewBook");bok4.yop = 2014;
	books = insert_book(bok4,books); // insert book4
	
	strcpy(bok5.Name,"Jain");strcpy(bok5.Sub,"Maths");strcpy(bok5.Author,"Rohit");strcpy(bok5.Acc_No,"5");strcpy(bok5.status,"available");
	strcpy(bok5.print_type,"NewBook");bok5.yop = 2018;
	books = insert_book(bok5,books); // insert book5
	
	strcpy(bok6.Name,"Jain");strcpy(bok6.Sub,"Chemistry");strcpy(bok6.Author,"Iyengar");strcpy(bok6.Acc_No,"6");strcpy(bok6.status,"available");
	strcpy(bok6.print_type,"NewBook");bok6.yop = 2017;
	books = insert_book(bok6,books); // insert book6
	
	strcpy(bok7.Name,"Learn Mechanics");strcpy(bok7.Sub,"Mechanics");strcpy(bok7.Author,"Ratnesh");strcpy(bok7.Acc_No,"7");strcpy(bok7.status,"available");
	strcpy(bok7.print_type,"NewBook");bok7.yop = 2015;
	books = insert_book(bok7,books); // insert book7
	
	strcpy(bok8.Name,"Learn C");strcpy(bok8.Sub,"Coding");strcpy(bok8.Author,"Kerning");strcpy(bok8.Acc_No,"8");strcpy(bok8.status,"available");
	strcpy(bok8.print_type,"NewBook");bok8.yop = 2012;
	books = insert_book(bok8,books); // insert book8
	
	strcpy(bok9.Name,"Electric");strcpy(bok9.Sub,"Electrical");strcpy(bok9.Author,"Virat");strcpy(bok9.Acc_No,"9");strcpy(bok9.status,"available");
	strcpy(bok9.print_type,"NewBook");bok9.yop = 2001;
	books = insert_book(bok9,books); // insert book9
	
	strcpy(bok10.Name,"Jain Iyengar");strcpy(bok10.Sub,"Maths");strcpy(bok10.Author,"Iyengar");strcpy(bok10.Acc_No,"10");strcpy(bok10.status,"available");
	strcpy(bok10.print_type,"NewBook");bok10.yop = 2002;
	books = insert_book(bok10,books); // insert book10
	
	member stu1,stu2,stu3;
	
	strcpy(stu1.Name,"Raheem");strcpy(stu1.Dep,"CSE");strcpy(stu1.ID,"BT19CSE067");strcpy(stu1.Status,"Student");stu1.nob = 0;stu1.notimes_finepaid = 1;
	stu = insert_mem(stu1,stu);  // insert Student 1
	fine = insert_mem_fine(stu1,fine);
	stu_nob = insert_mem_nob(stu1,stu_nob);
	
	strcpy(stu2.Name,"Vijit");strcpy(stu2.Dep,"CHEM");strcpy(stu2.ID,"BT19CHEM082");strcpy(stu1.Status,"Student");stu2.nob = 1;stu2.notimes_finepaid = 3;
	char Ac[] = "1";
	book b  ;
	Assign_book_stu(&books,Ac,&b,2020,11,11);
	stu2.iss_books[0] = b;
	stu = insert_mem(stu2,stu); // insert Student 2
	fine = insert_mem_fine(stu2,fine);
	stu_nob = insert_mem_nob(stu2,stu_nob);
	
	strcpy(stu3.Name,"Gowtham");strcpy(stu3.Dep,"CSE");strcpy(stu3.ID,"BT19CSE033");strcpy(stu1.Status,"Student");stu3.nob = 2;stu3.notimes_finepaid = 3;
	strcpy(Ac,"2");
	char Ac1[] = "3";
	book b1  ;
	book b2  ;
	Assign_book_stu(&books,Ac,&b1,2020,10,10);
	Assign_book_stu(&books,Ac1,&b2,2020,10,10);
	stu3.iss_books[0] = b1;
	stu3.iss_books[1] = b2;
	stu = insert_mem(stu3,stu); // insert Student 3
	fine = insert_mem_fine(stu3,fine);
	stu_nob = insert_mem_nob(stu3,stu_nob);
	
	member fac1,fac2,fac3;
	
	strcpy(fac1.Name,"Preetham");strcpy(fac1.Dep,"META");strcpy(fac1.ID,"PRMETA143");strcpy(fac1.Status,"Faculty");fac1.nob = 0;fac1.notimes_finepaid = 1;
	fac = insert_mem(fac1,fac); // insert Faculty 1
	fine = insert_mem_fine(fac1,fine);
	fac_nob = insert_mem_nob(fac1,fac_nob);
	
	strcpy(fac2.Name,"RAHUL");strcpy(fac2.Dep,"PHYSICS");strcpy(fac2.ID,"PRPHY333");strcpy(fac2.Status,"Faculty");fac2.nob = 1;fac2.notimes_finepaid = 3;
	strcpy(Ac,"4");
	book b3 ;
	Assign_book_fac(&books,Ac,&b3,2020,10,10);
	fac2.iss_books[0] = b3;
	fac = insert_mem(fac2,fac); // insert Faculty 2
	fine = insert_mem_fine(fac2,fine);
	fac_nob = insert_mem_nob(fac2,fac_nob);
	
	strcpy(fac3.Name,"Bhanu");strcpy(fac3.Dep,"MECH");strcpy(fac3.ID,"PRMECH122");strcpy(fac2.Status,"Faculty");fac3.nob = 2;fac3.notimes_finepaid = 3;
	strcpy(Ac,"5");
	strcpy(Ac1,"6");
	book b4 ;
	book b5 ;
	Assign_book_fac(&books,Ac,&b4,2020,9,10);
	Assign_book_fac(&books,Ac1,&b5,2020,9,10);
	fac3.iss_books[0] = b4;
	fac3.iss_books[1] = b5;
	fac = insert_mem(fac3,fac); // insert Faculty 3
	fine = insert_mem_fine(fac3,fine);
	fac_nob = insert_mem_nob(fac3,fac_nob);
	
	int state = 1;
	while(state == 1)
	{
		printf("\nEnter the following number to perform operation you want\n");
		printf("1:To search book by Name\n2:To search book by Author Name\n3:To Add student\n4:To Add Faculty\n");
		printf("5:To know students who issued max books\n6:To know faculty who issued max books\n7:To sort and display names of borrowers in descending order of no of books issued\n");
		printf("8:To Insert book\n9:To know the renew date of the book\n10:To know fine of student\n11:To know the fine of faculty\n12:To know the maximum fine of students\n");
		printf("13:To know the maximum fine of Faculty\n14:To issue a book if you are a student\n15:To issue a book if you are a faculty\n16: To print names of members who paid fine atleast thrice\n");
		printf("any other number:To exit\n");
		
		int c;
		scanf("%d",&c);

		switch(c)
		{
			case 1:
			{
				char NAME[50];
				printf("Enter the name of Book\n");
				scanf("%s",NAME);
				int count = searchBook_name(books,NAME);
				printf(" ----------No of Copies present = %d----------",count);
				break;
			}
			case 2:
			{
				char NAME[50];
				printf("Enter the name of Author\n");
				scanf("%s",NAME);
				searchBook_Author(books,NAME);
				break;
			}
			case 3:
			{
				stu = ADD_Student(stu,&fine,&stu_nob,&books);
				break;
			}
			case 4:
			{
				fac = ADD_Faculty(fac,&fine,&fac_nob,&books);
				break;
			}
			case 5:
			{
				int max = Max_No_of_books(stu);
				printf("Max no of books = %d\n",max);
				Max_books_mem(stu,max);
				break;
			}
			case 6:
			{
				int max = Max_No_of_books(fac);
				printf("Max no of books = %d\n",max);
				Max_books_mem(fac,max);
				break;
			}
			case 7:
			{
				merge(stu_nob,&fac_nob);
				traversal_mem_nob(fac_nob);
				break;
			}
			case 8:
			{
				books = INSERT_book(books);
				break;
			}
			case 9:
			{
				char Acc[20];
				printf("Enter the Accesion Number of the book :");
				scanf("%s",Acc);
				print_renew(&books,Acc);
				break;
			}
			case 10:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				printf("Enter the Student_ID : ");
				char S_ID[15];
				scanf("%s",S_ID);
				print_fine(&stu, S_ID, YEAR, MON, DAY);
				break;
			}
			case 11:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				printf("Enter the Faculty_ID : ");
				char F_ID[15];
				scanf("%s",F_ID);
				print_fine(&fac, F_ID, YEAR, MON, DAY);
				break;
			}
			case 12:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				int max_fine = Max_fine(stu, YEAR, MON, DAY);
				printf("The MAX Fine among students is = %d",max_fine);
				Max_fine_mem(stu, max_fine, YEAR, MON, DAY);
				break;
			}
			case 13:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				int max_fine = Max_fine(fac, YEAR, MON, DAY);
				printf("The MAX Fine among faculty is = %d",max_fine);
				Max_fine_mem(fac, max_fine, YEAR, MON, DAY);
				break;
			}
			case 14:
			{
				stu = Issue_book_stu(stu,&books);
				break;
			}
			case 15:
			{
				fac = Issue_book_fac(fac,&books);
				break;
			}
			case 16:
			{
				traversal_mem_fine(fine);
				break;
			}
			default:
			{
				state = 0;
			}
		}
	}
	
	return 0;
}
// To create a B tree node of book
btreeNode_book* createNode_book(book item, btreeNode_book* child, btreeNode_book* root) 
{
  	btreeNode_book* newNode;
  	newNode = (btreeNode_book*)malloc(sizeof(btreeNode_book));
  	newNode->data[1] = item;
  	newNode->count = 1;
  	newNode->link[0] = root;
  	newNode->link[1] = child;
  	return newNode;
}

// To insert value in book node
void insertValue_book(book item, int pos, btreeNode_book* node, btreeNode_book* child) 
{
  	int j = node->count;
  	while (j > pos) 
  	{
	  	node->data[j + 1] = node->data[j];
      	node->link[j + 1] = node->link[j];
      	j--;
  	}
  	node->data[j + 1] = item;
  	node->link[j + 1] = child;
  	node->count++;
}

// To split node of book 
void splitNode_book(book item, book *pval, int pos, btreeNode_book* node, btreeNode_book* child, btreeNode_book** newNode) 
{
  	int median, j;

  	if (pos > MIN)
   		median = MIN + 1;
  	else
    	median = MIN;

  *newNode = (btreeNode_book*)malloc(sizeof(btreeNode_book));
  j = median + 1;
  while (j <= MAX) 
  {
    (*newNode)->data[j - median] = node->data[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) 
  {
    insertValue_book(item, pos, node, child);
  } 
  else 
  {
    insertValue_book(item, pos - median, *newNode, child);
  }
  *pval = node->data[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// To compare two books 
int compare_book(book item1,book item2)
{
	int ret_val = 0;
	if (strcmp(item1.Sub, item2.Sub) < 0 )
	{
		ret_val = 1;
	}
	else if(strcmp(item1.Sub, item2.Sub) == 0) 
	{
		if(strcmp(item1.Name, item2.Name) < 0)
		{
			ret_val = 1;
		}
		else if(strcmp(item1.Name, item2.Name) == 0)
		{
			if(strcmp(item1.Author, item2.Author) < 0)
			{
				ret_val = 1;
			}
			else if(strcmp(item1.Author, item2.Author) == 0)
			{
				if(item1.yop > item2.yop)
				{
					ret_val = 1;
				}
			}
		}
	}
	return ret_val;
}

// To set the value of node
int setNodeValue_book(book item, book* pval, btreeNode_book* node, btreeNode_book** child) 
{
  	int pos;
  	if (!node) 
	{
    	*pval = item ;
    	*child = NULL;
    	return 1;
  	}

  	if(compare_book(item,node->data[1]))
  	{
  		pos = 0;
	}
	else 
	{
		pos = node->count;
		while(compare_book(item,node->data[pos]) && pos > 1)
		{
			pos--;
		}
    }
  	if (setNodeValue_book(item, pval, node->link[pos], child)) 
	{
    	if (node->count < MAX) 
		{
      		insertValue_book(*pval, pos, node, *child);
    	} 
		else 
		{
      		splitNode_book(*pval, pval, pos, node, *child, child);
      		return 1;
    	}
  	}
 	return 0;
}

// To insert a book
btreeNode_book* insert_book(book item,btreeNode_book* root) 
{
  	int flag;
  	book i;
  	btreeNode_book* child;

  	flag = setNodeValue_book(item, &i, root, &child);
  	if (flag)
  	{
		root = createNode_book(i, child, root);
	}
	return root;
}

// To traverse the B tree of Books
void traversal_book(btreeNode_book* myNode) 
{
  	int i;
  	if (myNode) 
	{
    	for (i = 0; i < myNode->count; i++) 
		{
      		traversal_book(myNode->link[i]);
      		printf("%s ", myNode->data[i + 1].Name);
      		
    	}
    	traversal_book(myNode->link[i]);
  	}
}

// To Create a Node of Member
btreeNode_mem* createNode_mem(member item, btreeNode_mem *child, btreeNode_mem* root) 
{
  	btreeNode_mem *newNode;
  	newNode = (btreeNode_mem*)malloc(sizeof(btreeNode_mem));
  	newNode->data[1] = item;
  	newNode->count = 1;
  	newNode->link[0] = root;
  	newNode->link[1] = child;
  	return newNode;
}

// To insert a value in member node
void insertValue_mem(member item, int pos, btreeNode_mem *node, btreeNode_mem *child) 
{
  	int j = node->count;
  	while (j > pos) 
  	{
	  	node->data[j + 1] = node->data[j];
      	node->link[j + 1] = node->link[j];
      	j--;
  	}
  	node->data[j + 1] = item;
  	node->link[j + 1] = child;
  	node->count++;
}

// To split a member Node
void splitNode_mem(member item, member *pval, int pos, btreeNode_mem *node, btreeNode_mem *child, btreeNode_mem **newNode) 
{
  	int median, j;

  	if (pos > MIN)
   		median = MIN + 1;
  	else
    	median = MIN;

  *newNode = (btreeNode_mem*)malloc(sizeof(btreeNode_mem));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->data[j - median] = node->data[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) 
  {
    insertValue_mem(item, pos, node, child);
  } 
  else 
  {
    insertValue_mem(item, pos - median, *newNode, child);
  }
  *pval = node->data[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// To compare two Members
int compare_member(member mem1, member mem2)
{
	int ret_val = 0;
	if(strcmp(mem1.Dep,mem2.Dep) < 0)
	{
		ret_val = 1;
	}
	else if(strcmp(mem1.Dep,mem2.Dep) == 0)
	{
		if(strcmp(mem1.ID,mem2.ID) < 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}

// To set the value to node
int setNodeValue_mem(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child) 
{
  	int pos;
  	if (!node) 
	{
    	*pval = item ;
    	*child = NULL;
    	return 1;
  	}

  	if(compare_member(item,node->data[1]))
  	{
  		pos = 0;
	}
	else 
	{
		pos = node->count;
		while(compare_member(item,node->data[pos]) && pos > 1)
		{
			pos--;
		}
    }
  	if (setNodeValue_mem(item, pval, node->link[pos], child)) 
	{
    	if (node->count < MAX) 
		{
      		insertValue_mem(*pval, pos, node, *child);
    	} 
		else 
		{
      		splitNode_mem(*pval, pval, pos, node, *child, child);
      		return 1;
    	}
  	}
 	return 0;
}

// To insert a member in B tree of members
btreeNode_mem* insert_mem(member item,btreeNode_mem* root) 
{
  	int flag;
  	member i;
  	btreeNode_mem *child;

  	flag = setNodeValue_mem(item, &i, root, &child);
  	if (flag)
  	{
		root = createNode_mem(i, child, root);
	}
	return root;
}

// To set the value to node for btree of FINE
int setNodeValue_mem_fine(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child) 
{
  	int pos;
  	if (!node) 
	{
    	*pval = item ;
    	*child = NULL;
    	return 1;
  	}

  	if(item.notimes_finepaid < node->data[1].notimes_finepaid) 
  	{
  		pos = 0;
	}
	else 
	{
		pos = node->count;
		while((item.notimes_finepaid < node->data[pos].notimes_finepaid) && pos > 1)
		{
			pos--;
		}
    }
  	if (setNodeValue_mem_fine(item, pval, node->link[pos], child)) 
	{
    	if (node->count < MAX) 
		{
      		insertValue_mem(*pval, pos, node, *child);
    	} 
		else 
		{
      		splitNode_mem(*pval, pval, pos, node, *child, child);
      		return 1;
    	}
  	}
 	return 0;
}

// To insert a member in B tree of members
btreeNode_mem* insert_mem_fine(member item,btreeNode_mem* root) 
{
  	int flag;
  	member i;
  	btreeNode_mem *child;

  	flag = setNodeValue_mem_fine(item, &i, root, &child);
  	if (flag)
  	{
		root = createNode_mem(i, child, root);
	}
	return root;
}

// To traverse the B tree of Members
void traversal_mem_fine(btreeNode_mem* myNode) 
{
  	int i;
  	if (myNode) 
	{
    	for (i = 0; i < myNode->count; i++) 
		{
      		traversal_mem_fine(myNode->link[i]);
      		if(myNode->data[i+1].notimes_finepaid >= 3)
      		{
      			printf("------%s\t------",myNode->data[i+1].Name);
			}
      	}
    	traversal_mem_fine(myNode->link[i]);
  	}
}

// To compare two Members
int compare_member_nob(member mem1, member mem2)
{
	int ret_val = 0;
	if(mem1.nob < mem2.nob)
	{
		ret_val = 1;
	}
	else if(mem1.nob == mem2.nob)
	{
		if(strcmp(mem1.Name,mem2.Name) < 0)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}

// To set the value to node for btree of stu_nob and fac_nob
int setNodeValue_mem_nob(member item, member* pval, btreeNode_mem* node, btreeNode_mem** child) 
{
  	int pos;
  	if (!node) 
	{
    	*pval = item ;
    	*child = NULL;
    	return 1;
  	}

  	if(compare_member_nob(item,node->data[1])) 
  	{
  		pos = 0;
	}
	else 
	{
		pos = node->count;
		while((compare_member_nob(item,node->data[1])) && pos > 1)
		{
			pos--;
		}
    }
  	if (setNodeValue_mem_nob(item, pval, node->link[pos], child)) 
	{
    	if (node->count < MAX) 
		{
      		insertValue_mem(*pval, pos, node, *child);
    	} 
		else 
		{
      		splitNode_mem(*pval, pval, pos, node, *child, child);
      		return 1;
    	}
  	}
 	return 0;
}

// To insert a member in B tree of members 
btreeNode_mem* insert_mem_nob(member item,btreeNode_mem* root) 
{
  	int flag;
  	member i;
  	btreeNode_mem *child;

  	flag = setNodeValue_mem_nob(item, &i, root, &child);
  	if (flag)
  	{
		root = createNode_mem(i, child, root);
	}
	return root;
}

// To traverse the B tree of Members
void traversal_mem_nob(btreeNode_mem* myNode) 
{
  	int i;
  	if (myNode) 
	{
    	for (i = 0; i < myNode->count; i++) 
		{
      		traversal_mem_nob(myNode->link[i]);
      		printf("--------%s\t-------",myNode->data[i+1].Name);	
      	}
    	traversal_mem_nob(myNode->link[i]);
  	}
}

// To search the book by Name
int searchBook_name(btreeNode_book* myNode,char* name)
{
	int i,c = 0;
	if(myNode)
	{
		for(i = 0; i < myNode->count; i++)
		{
			c = c + searchBook_name(myNode->link[i],name);
			if(strstr(myNode->data[i+1].Name,name))
			{
				printf("-------- Author : %s\n",myNode->data[i+1].Author);
				printf("-------- Year of Print : %d\n",myNode->data[i+1].yop);
				printf("-------- Status : %s\n", myNode->data[i+1].status);
				c = c + 1;
			}
		}
		c = c + searchBook_name(myNode->link[i],name);
	}
	return c;
}

// To search the book by name of Author
void searchBook_Author(btreeNode_book* myNode,char* Author)
{
	int i=0;
	if(myNode)
	{
		for(i = 0; i < myNode->count; i++)
		{
			searchBook_Author(myNode->link[i],Author);
			if(strcmp(myNode->data[i+1].Author,Author)==0)
			{
				printf("--------- %s ---------\n",myNode->data[i+1].Name);
			}	
		} 
		searchBook_Author(myNode->link[i],Author);
	}
}

// To search Acc No of the,this func is used in ADD_Student 
void search_AccNo_stu(btreeNode_book** books, char* Acc, book* bok)
{
	btreeNode_book* ptr;
	ptr = *books;
	int i,j;
	if(ptr)
	{
		for(i=0; i<ptr->count ;i++)
		{
			search_AccNo_stu(&(ptr->link[i]),Acc,bok);
			if(strcmp(ptr->data[i+1].Acc_No,Acc)==0)
			{
				if(strcmp(ptr->data[i+1].status ,"issued") != 0)
				{
					strcpy(ptr->data[i+1].status, "issued");
					printf("Enter the issued date in ordder of day, month, year:\n");
					scanf("%d",&ptr->data[i+1].issued.day);
					scanf("%d",&ptr->data[i+1].issued.month);
					scanf("%d",&ptr->data[i+1].issued.yr);
					ptr->data[i+1] = Renew_date_stu(ptr->data[i+1]);
					printf("---------Renew date of the book is : ");
					printf("%d-",ptr->data[i+1].renew.day);
					printf("%d-",ptr->data[i+1].renew.month);
					printf("%d\n",ptr->data[i+1].renew.yr);
					*bok = ptr->data[i+1];
					
				}
				else
				{	
					printf("This Book is already issued by someone");
				}
			}
		}
		search_AccNo_stu(&(ptr->link[i]),Acc,bok);
	}
}

// To search Acc No of the,this func is used in  ADD_Faculty
void search_AccNo_fac(btreeNode_book** books, char* Acc, book* bok)
{
	btreeNode_book* ptr;
	ptr = *books;
	int i,j;
	if(ptr)
	{
		for(i=0; i<ptr->count;i++)
		{
			search_AccNo_fac(&(ptr->link[i]),Acc,bok);
			if(strcmp(ptr->data[i+1].Acc_No,Acc)==0)
			{
				if(strcmp(ptr->data[i+1].status ,"issued") != 0)
				{
					strcpy(ptr->data[i+1].status, "issued");
					printf("Enter the issued date in ordder of day, month, year:\n");
					scanf("%d",&ptr->data[i+1].issued.day);
					scanf("%d",&ptr->data[i+1].issued.month);
					scanf("%d",&ptr->data[i+1].issued.yr);
					ptr->data[i+1] = Renew_date_fac(ptr->data[i+1]);
					printf("---------Renew date of the book is : ");
					printf("%d-",ptr->data[i+1].renew.day);
					printf("%d-",ptr->data[i+1].renew.month);
					printf("%d\n",ptr->data[i+1].renew.yr);
					*bok = ptr->data[i+1];
				}
				else
				{
					printf("This Book is already issued by someone");
				}
			}
		}
		search_AccNo_fac(&(ptr->link[i]),Acc,bok);
	}
}

// To Add a Student 
btreeNode_mem* ADD_Student(btreeNode_mem* stu, btreeNode_mem** fine, btreeNode_mem** stu_nob, btreeNode_book** books)
{
	member stu1;
	char Name[50],Dep[20],ID[15];
	int nob;
	printf("Enter the details of the student\n");
	printf("Enter the student name : ");
	scanf("%s",stu1.Name);
	printf("\nEnter the department of student : ");
	scanf("%s",stu1.Dep);
	printf("\nEnter the ID of student : ");
	scanf("%s",stu1.ID);
	printf("\nEnter the no of books issued Max 2,if creating just an account enter 0 : ");
	scanf("%d",&stu1.nob);
	if(stu1.nob > 0)
	{
		int i = 0;
		while(i < stu1.nob)
		{
			printf("\nEnter the Accesion number of books that you have issued\n");
			char Acc[20];
			scanf("%s",Acc);
			book bok ;
			search_AccNo_stu(books,Acc,&bok);
			stu1.iss_books[i] = bok;
			i++;
		}
	}
	stu1.notimes_finepaid = 0;
	strcpy(stu1.Status,"Student");
	stu = insert_mem(stu1,stu);
	*fine = insert_mem_fine(stu1,*fine);
	*stu_nob = insert_mem_nob(stu1,*stu_nob);
	return stu;
}

// To Add a Faculty member
btreeNode_mem* ADD_Faculty(btreeNode_mem* fac, btreeNode_mem** fine, btreeNode_mem** fac_nob, btreeNode_book** books)
{
	member fac1;
	char Name[50],Dep[20],ID[15];
	int nob;
	printf("Enter the details of the faculty\n");
	printf("Enter the faculty name : ");
	scanf("%s",fac1.Name);
	printf("\nEnter the department of faculty : ");
	scanf("%s",fac1.Dep);
	printf("\nEnter the ID of faculty : ");
	scanf("%s",fac1.ID);
	printf("\nEnter the no of books issued Max 4,if creating just an account enter 0 : ");
	scanf("%d",&fac1.nob);
	if(fac1.nob > 0)
	{
		int i = 0;
		while(i < fac1.nob)
		{
			printf("\nEnter the Accesion number of books that you have issued\n");
			char Acc[20];
			scanf("%s",Acc);
			book bok ;
			search_AccNo_fac(books,Acc,&bok);
			fac1.iss_books[i] = bok;
			i++;
		}
	}
	fac1.notimes_finepaid = 0;
	strcpy(fac1.Status,"Faculty");
	fac = insert_mem(fac1,fac);
	*fine = insert_mem_fine(fac1,*fine);
	*fac_nob = insert_mem_nob(fac1,*fac_nob);
	return fac;
}

// To find Max no of books with a member
int Max_No_of_books(btreeNode_mem* myNode)
{
	int i,max = 0;
	if (myNode) 
	{
    	for (i = 0; i < myNode->count; i++) 
		{
      		Max_No_of_books(myNode->link[i]);
      		if(myNode->data[i+1].nob > max)
      		{
      			max =  myNode->data[i+1].nob;
			}
      	}
    	Max_No_of_books(myNode->link[i]);
  	}
  	return max;
}

// To print names who are having MAX no of Books
void Max_books_mem(btreeNode_mem* myNode,int max)
{
	int i;
	if (myNode) 
	{
    	for (i = 0; i < myNode->count; i++) 
		{
      		Max_books_mem(myNode->link[i],max);
      		if(myNode->data[i+1].nob == max)
      		{
      			printf("-------------%s	",myNode->data[i+1].Name);
			}
      	}
    	Max_books_mem(myNode->link[i],max);
  	}
}

// To insert a Book
btreeNode_book* INSERT_book(btreeNode_book* books)
{
	book bok;
	printf("Enter the details of the book\n");
	printf("Enter the name of book : ");
	scanf("%s",bok.Name);
	printf("\nEnter the subject of book : ");
	scanf("%s",bok.Sub);
	printf("\nEnter the Author name : ");
	scanf("%s",bok.Author);
	printf("\nEnter NewPrint or NewBook : ");
	scanf("%s",bok.print_type);
	printf("\nEnter the year of publication : ");
	scanf("%d",&bok.yop);
	printf("\nEnter the Accession number : ");
	scanf("%s",bok.Acc_No);
	printf("\nEnter the status of book : ");
	scanf("%s",bok.status);
	books = insert_book(bok,books);
	
	return books;
}

// To print renew Date
void print_renew(btreeNode_book** books,char* Acc)
{	btreeNode_book* ptr;
	ptr = *books;
	int i;
	if(ptr)
	{
		for(i = 0; i < ptr->count; i++)
		{
			print_renew(&(ptr->link[i]),Acc);
			if(strcmp(ptr->data[i+1].Acc_No,Acc) == 0)
			{
				if(strcmp(ptr->data[i+1].status, "issued") == 0)
				{
					printf("---------%d-",ptr->data[i+1].renew.day);
					printf("%d-",ptr->data[i+1].renew.month);
					printf("%d",ptr->data[i+1].renew.yr);
				}
				else
				{
					printf("---------This  book is not issued-------");
				}
			}
		}
		print_renew(&(ptr->link[i]),Acc);
	}
}

// To find the renew date of book for student  ..considering he/she returns on 15th day from issuing the book.
book Renew_date_stu(book bok)
{
	if(((bok.issued.yr%4==0)&&(bok.issued.yr%100!=0)||(bok.issued.yr%400==0)) && (bok.issued.month==02))
	{


	        if(bok.issued.day<=15)
			{
		   		bok.renew.day=bok.issued.day+14;
		   		bok.renew.month=02;
		   		bok.renew.yr=bok.issued.yr;
			}
	        else
			{
		   		bok.renew.day=14-(29-bok.issued.day);
		   		bok.renew.month=03;
		   		bok.renew.yr=bok.issued.yr;
			}

	}
	else
	{
		if(bok.issued.month==02)
		{
		  if(bok.issued.day<=14)
		  {
		    bok.renew.day=bok.issued.day+14;
		    bok.renew.month=02;
		    bok.renew.yr=bok.issued.yr;
		  }
		  else
	 	  {
		    bok.renew.day=14-(28-bok.issued.day);
		    bok.renew.month=03;
		    bok.renew.yr=bok.issued.yr;
		  }
		}
		if(bok.issued.month==12)
		{
		  if(bok.issued.day<=17)
		  {
		    bok.renew.day=bok.issued.day+14;
		    bok.renew.month=12;
		    bok.renew.yr=bok.issued.yr;
		  }
		  else
		  {
		    bok.renew.day=14-(31-bok.issued.day);
		    bok.renew.month=01;
		    bok.renew.yr=bok.issued.yr+1;
		  }
		}
		if(bok.issued.month==4||bok.issued.month==06||bok.issued.month==9||bok.issued.month==11)
		{
			if(bok.issued.day<=16)
			{
			   bok.renew.day=bok.issued.day+14;
			   bok.renew.month=bok.issued.month;
			   bok.renew.yr=bok.issued.yr;
			}
			else
			{
			    bok.renew.day=14-(30-bok.issued.day);
			    bok.renew.month=bok.issued.month+1;
			    bok.renew.yr=bok.issued.yr;
			}
		}
		else if(bok.issued.month==1||bok.issued.month==3||bok.issued.month==5||bok.issued.month==7||bok.issued.month==8||bok.issued.month==10)
		{
			if(bok.issued.day<=17)
			{
			   bok.renew.day=bok.issued.day+14;
			   bok.renew.month=bok.issued.month;
			   bok.renew.yr=bok.issued.yr;
			}
			else
			{
			    bok.renew.day=14-(31-bok.issued.day);
				bok.renew.month=bok.issued.month+1;
			    bok.renew.yr=bok.issued.yr;
			}
		}
	}

	return bok;
}


// To find the renew date of book for faculty  ..considering he/she returns on 31th day from issuing the book.
book Renew_date_fac(book bok)
{
		if(((bok.issued.yr%4==0)&&(bok.issued.yr%100!=0)||(bok.issued.yr%400==0)) && ((bok.issued.month==2)||(bok.issued.month==1)))
		{
			if(bok.issued.month == 1)
			{
				bok.renew.day = bok.issued.day + 30;
				if(bok.renew.day > 31 && bok.renew.day <= 60)
				{
					bok.renew.day = (bok.renew.day)%31;
					bok.renew.month = bok.issued.month + 1;
				}
				else if(bok.renew.day > 60)
				{
					bok.renew.day = (bok.renew.day)%30;
					bok.renew.month = bok.issued.month + 2;
				}
				else
				{
					bok.renew.month = bok.issued.month;
				}
				bok.renew.yr = bok.renew.yr;
			}
			else if(bok.issued.month = 02)
			{
				bok.renew.day = bok.issued.day + 1;
				bok.renew.month = bok.issued.month + 1;
				bok.renew.yr = bok.issued.yr;
			}
		}
		else
		{
			if(bok.issued.month == 1)
			{
				bok.renew.day = bok.issued.day + 30;
				if(bok.renew.day > 31 && bok.renew.day < 60)
				{
					bok.renew.day = (bok.renew.day)%31;
					bok.renew.month = bok.issued.month + 1;
				}
				else if(bok.renew.day >=60)
				{
					bok.renew.day = (bok.renew.day)%30 + 1;
					bok.renew.month = bok.issued.month + 2;
				}
				else
				{
					bok.renew.month = bok.issued.month;
				}
				bok.renew.yr = bok.issued.yr;
			}
			else if(bok.issued.month == 2)
			{
				bok.renew.day = bok.issued.day + 2;
				bok.renew.month = bok.issued.month + 1;
				bok.renew.yr = bok.issued.yr;
			}
			else if(bok.issued.month == 12)
			{
				bok.renew.day = bok.issued.day + 30;
				if(bok.renew.day > 31)
				{
					bok.renew.day = (bok.renew.day)%31;
					bok.renew.month = 1;
					bok.renew.yr = bok.issued.yr + 1;
				}
				else
				{
					bok.renew.month = bok.issued.month;
					bok.renew.yr = bok.issued.yr;
				}
			}
			else if(bok.issued.month==3||bok.issued.month==5||bok.issued.month==7||bok.issued.month==8||bok.issued.month==10)
			{
				bok.renew.day = bok.issued.day + 30;
				if(bok.renew.day > 31)
				{
					bok.renew.day = (bok.renew.day)%31;
					bok.renew.month = bok.issued.month + 1;
				}
				else
				{
					bok.renew.month = bok.issued.month;
				}
				bok.renew.yr = bok.issued.yr;
			}
			else if(bok.issued.month==4||bok.issued.month==06||bok.issued.month==9||bok.issued.month==11)
			{
				bok.renew.day = bok.issued.day;
				bok.renew.month = bok.issued.month + 1;
				bok.renew.yr = bok.issued.yr;
			}

		}
		return bok;
}

// To calculaate fine 
int Fine(member mem,int YEAR,int MON,int DAY)
{
	int fine=0,i=0;
	while(i < mem.nob)
	{
		if(((YEAR%4==0)&&(YEAR%100!=0))||YEAR%400==0)
		{
			if(mem.iss_books[i].renew.month==MON)
			{
				fine=fine+(DAY-mem.iss_books[i].renew.day)*50;
			}
			else if(mem.iss_books[i].renew.month==2)
			{
				fine=fine+(29-mem.iss_books[i].renew.day+DAY)*50;
			}
			else if(mem.iss_books[i].renew.month==4||mem.iss_books[i].renew.month==6||mem.iss_books[i].renew.month==9||mem.iss_books[i].renew.month==11)
			{
	   			fine=fine+(30-mem.iss_books[i].renew.day+DAY)*50;
			}
			else
			{
				fine=fine+(31-mem.iss_books[i].renew.day+DAY)*50;
			}
		}
		else
	   	{
			if(mem.iss_books[i].renew.month==MON)
			{
				fine=fine+(DAY-mem.iss_books[i].renew.day)*50;
			}
			else if(mem.iss_books[i].renew.month==2)
			{
				fine=fine+(28-mem.iss_books[i].renew.day+DAY)*50;
			}
			else if(mem.iss_books[i].renew.month==4||mem.iss_books[i].renew.month==6||mem.iss_books[i].renew.month==9||mem.iss_books[i].renew.month==11)
			{
	            fine=fine+(30-mem.iss_books[i].renew.day+DAY)*50;
			}
			else
			{
				fine=fine+(31-mem.iss_books[i].renew.day+DAY)*50;
			}
	   }
	   i++;
	}
	return fine;
}

// To calculate MAX fine
int Max_fine(btreeNode_mem* myNode,int YEAR,int MON,int DAY)
{
	int i,max = 0,fine;
	if (myNode) 
	{
    		for (i = 0; i < myNode->count; i++) 
		{
      			Max_No_of_books(myNode->link[i]);
      			fine = Fine(myNode->data[i+1],YEAR,MON,DAY);
      			if(fine > max)
      			{
      				max =  fine;
			}
      		}
    		Max_No_of_books(myNode->link[i]);
  	}
  	return max;
}

// To print fine
void print_fine(btreeNode_mem** mem,char* ID,int YEAR,int MON,int DAY)
{
	btreeNode_mem* ptr;
	ptr = *mem;
	int i;
	if(ptr)
	{
		for(i = 0; i < (*mem)->count; i++)
		{
			print_fine(&(ptr->link[i]),ID,YEAR,MON,DAY);
			if(strcmp((*mem)->data[i+1].ID,ID) == 0)
			{
				printf("-----------Fine = %d",Fine(ptr->data[i+1],YEAR,MON,DAY));
			}
		}
		print_fine(&(ptr->link[i]),ID,YEAR,MON,DAY);
	}
}

// To print names of members having maximum fines
void Max_fine_mem(btreeNode_mem* myNode,int max,int YEAR,int MON,int DAY)
{
	int i,fine;
	if (myNode) 
	{
    		for (i = 0; i < myNode->count; i++) 
		{
      			Max_books_mem(myNode->link[i],max);
      			fine = Fine(myNode->data[i+1],YEAR,MON,DAY);
      			if(fine == max)
      			{
      				printf("----------%s	",myNode->data[i+1].Name);
			}
      		}
    		Max_books_mem(myNode->link[i],max);
  	}
}

// To search student by ID ,and issue books, this func is used in issue operation by student
void search_stu_ID(btreeNode_mem** stu, char* ID, btreeNode_book** books)
{
	btreeNode_mem* ptr;
	ptr = *stu;
	int i;
	if(ptr != NULL)
	{	
		for(i = 0; i < ptr->count; i++)
		{
				search_stu_ID(&(ptr->link[i]), ID, books);
				if(strcmp(ptr->data[i+1].ID,ID)==0)
				{
					while(ptr->data[i+1].nob < 2)
					{
						int j = ptr->data[i+1].nob;
						char Acc[15];
						printf("\nEnter the Accession number of the book that you are issuing : ");
						scanf("%s",Acc);
						book bok ;
						search_AccNo_stu(books, Acc, &bok);
						ptr->data[i+1].iss_books[j] = bok;
						ptr->data[i+1].nob = ptr->data[i+1].nob + 1;
					}
				}
		}
		search_stu_ID(&(ptr->link[i]), ID, books);
	}
}

// To issue books by student
btreeNode_mem* Issue_book_stu(btreeNode_mem* stu, btreeNode_book** books )
{
	printf("Enter student ID : ");
	char S_ID[20];
	scanf("%s",S_ID);
	search_stu_ID(&stu,S_ID,books);
	return stu;
}

// To search faculty by ID ,and issue books, this func is used in issue operation by student
void search_fac_ID(btreeNode_mem** fac, char* ID, btreeNode_book** books)
{
	btreeNode_mem* ptr;
	ptr = *fac;
	int i;
	if(ptr != NULL)
	{	
		for(i = 0; i < ptr->count; i++)
		{
				search_fac_ID(&(ptr->link[i]), ID, books);
				if(strcmp(ptr->data[i+1].ID,ID)==0)
				{
					while(ptr->data[i+1].nob < 4)
					{
						int j = ptr->data[i+1].nob;
						char Acc[15];
						printf("\nEnter the Accession number of the book that you are issuing : ");
						scanf("%s",Acc);
						book bok ;
						search_AccNo_fac(books, Acc, &bok);
						ptr->data[i+1].iss_books[j] = bok;
						ptr->data[i+1].nob = ptr->data[i+1].nob + 1;
					}
				}
		}
		search_fac_ID(&(ptr->link[i]), ID, books);
	}
}

// To issue books by faculty
btreeNode_mem* Issue_book_fac(btreeNode_mem* fac, btreeNode_book** books )
{
	printf("Enter Faculty ID : ");
	char F_ID[20];
	scanf("%s",F_ID);
	search_fac_ID(&fac,F_ID,books);
	return fac;
}

void merge(btreeNode_mem* stu_nob, btreeNode_mem** fac_nob)
{
	btreeNode_mem* ptr;
	ptr = *fac_nob; 
	int i;
	if(stu_nob)
	{
		for(i = 0; i < stu_nob->count; i++)
		{
			merge(stu_nob->link[i],fac_nob);
			ptr = insert_mem_nob(stu_nob->data[i+1],ptr);
		}
		merge(stu_nob->link[i],fac_nob);
	}
}
void Assign_book_stu(btreeNode_book** books, char* Acc, book* bok,int YEAR, int MON, int DAY)
{
	btreeNode_book* ptr;
	ptr = *books;
	int i,j;
	if(ptr)
	{
		for(i=0; i<ptr->count;i++)
		{
			Assign_book_stu(&(ptr->link[i]),Acc,bok,YEAR,MON,DAY);
			if(strcmp(ptr->data[i+1].Acc_No,Acc)==0)
			{
				if(strcmp(ptr->data[i+1].status ,"issued") != 0)
				{
					strcpy(ptr->data[i+1].status, "issued");
					ptr->data[i+1].issued.day = DAY;
					ptr->data[i+1].issued.month = MON;
					ptr->data[i+1].issued.yr = YEAR;
					ptr->data[i+1] = Renew_date_stu(ptr->data[i+1]);
					printf("---------Renew date of the book is : ");
					printf("%d-",ptr->data[i+1].renew.day);
					printf("%d-",ptr->data[i+1].renew.month);
					printf("%d\n",ptr->data[i+1].renew.yr);
					*bok = ptr->data[i+1];
				}
				else
				{
					printf("This Book is already issued by someone");
				}
			}
		}
		Assign_book_stu(&(ptr->link[i]),Acc,bok,YEAR,MON,DAY);
	}
}

void Assign_book_fac(btreeNode_book** books, char* Acc, book* bok, int YEAR, int MON, int DAY)
{
	btreeNode_book* ptr;
	ptr = *books;
	int i,j;
	if(ptr)
	{
		for(i=0; i<ptr->count;i++)
		{
			Assign_book_fac(&(ptr->link[i]),Acc,bok,YEAR,MON,DAY);
			if(strcmp(ptr->data[i+1].Acc_No,Acc)==0)
			{
				if(strcmp(ptr->data[i+1].status ,"issued") != 0)
				{
					strcpy(ptr->data[i+1].status, "issued");
					ptr->data[i+1].issued.day = DAY;
					ptr->data[i+1].issued.month = MON;
					ptr->data[i+1].issued.yr = YEAR;
					ptr->data[i+1] = Renew_date_fac(ptr->data[i+1]);
					printf("---------Renew date of the book is : ");
					printf("%d-",ptr->data[i+1].renew.day);
					printf("%d-",ptr->data[i+1].renew.month);
					printf("%d\n",ptr->data[i+1].renew.yr);
					*bok = ptr->data[i+1];
				}
				else
				{
					printf("This Book is already issued by someone");
				}
			}
		}
		Assign_book_fac(&(ptr->link[i]),Acc,bok,YEAR,MON,DAY);
	}
}

