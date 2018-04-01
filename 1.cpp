#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;        
                                
typedef struct ListNode {
    ElementType  Element;       
    ListNode* Next;       
}Node, *PNode;


PNode Create_List(void) {                         //�����µ����� 
    int len ;   
    int val ;   
    PNode PHead = (PNode)malloc(sizeof(Node));    

    if (PHead == NULL)    
    {
        printf("�ռ����ʧ�� \n");
        exit(-1);
    }

    PNode PTail = PHead;    
    PTail->Next = NULL;   
    len=0;      
    for (int i = 0; i < len; i++) {

        PNode pNew = (PNode)malloc(sizeof(Node));    
        if (pNew == NULL) {
            printf("�����½ڵ�ʧ��\n");
            exit(-1);
        }
       printf("������� %d ���ڵ�����ݣ�", i + 1);
        scanf("%d", &val);    

        pNew->Element = val;    
        PTail->Next = pNew;    
        pNew->Next = NULL;       
        PTail = pNew;   
    }   
    
    return PHead;    
}

void Insert_List(PNode List, int pos, int val) {                 //�ڱ�List��posλ�ò���ֵΪval��Ԫ�� �����룩 
    int position = 0;
    PNode P = List;    
                    
    while (P != NULL&&position<pos - 1)
    {
        P = P->Next;
        ++position;
    }
    PNode Tmp = (PNode)malloc(sizeof(Node));    
    if (Tmp == NULL)
    {
        printf("�ڴ����ʧ�ܣ�");
        exit(-1);
    }
   
    Tmp->Element = val;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}


int Is_Same(PNode List,int val){                      //�ڱ�List�в�ѯ�Ƿ���ֵ��val��ͬ��Ԫ�أ����򷵻�false��û���򷵻�true �����أ� 
	PNode P = List -> Next;
	if (P == NULL){
        printf("����Ϊ��");
        }
        while(P!=NULL){
        	if(P->Element==val){	
        	printf("\n���ظ���\n\n");
			return 0;
			break;
			}
		P=P->Next;
		}
		return 1; 
}
void Go_List(PNode List) {            //��������List 
    PNode P = List->Next;   
    printf("���������ֵΪ��");
    if (P == NULL)
        printf("����Ϊ��");
    while (P != NULL)        
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

int Get_Num(PNode List ,int val){              //�ڱ�List�в���ֵΪval��Ԫ����� ����ֵ���ң� 
	int j;
	PNode P = List->Next; 
	j=0;
	while(P!=NULL){
		P=P->Next;
		++j;
		if(val==P->Element){
		break;
		}
	}	
		return j;

}

int Get_Elem(PNode List,int num){              //�ڱ�List�в�����ŵ�num��ֵ ������Ų��ң� 
	if(num<0){
		return 99999999;
	}
	int i=0;
	int k;
	PNode P = List->Next;
	
	while(P!=NULL&&i<num){
		P=P->Next; 
		++i;
	} 
	k=P->Element;
} 

int Change_Value(PNode List,int num,int val){              //�ѱ�List�У����Ϊnum ��Ԫ�ص�ֵ�滻Ϊval ���޸������ֵ�� 
	PNode P = List->Next;
	int k=1;
	while(P!=NULL&&k<num){
		P=P->Next;
		++k;
	}
	P->Element=val;
}
void init()
{
	
	char a;
	char reg;
	int password;
    printf("Welcome to Peppa pig lottery-station");
   
    printf("Do you have accounts?[Y/N]");
    scanf("%c",&a);
    if(a == 'Y'| a == 'y' ) //login
    {
    	printf("Please input your id munber:");
    	scanf("%d",id);
    	Insert_List(userid, 1, id);
		printf("Please input your password:");
		scanf("%d",&password);
	
		if(id==0)//ֻ��0���ǹ���Ա 
		{
			admin();//����Ա��¼ 
		} 
		
    	else if(id=={1,2,3,4,5,6,7,8,9})
		{
			person();//��ͨ�û���¼ 
		} 
		else
		{
			printf("User can't be found!Write N to reginster\n");
			scanf("%c",&reg);
			if(reg=='N')
			{
				register();
			}
			
		}
			
	}
	else if(a == 'N' | a == 'n')
	{
		register();
	}
    

}
void person()
{
	//��ȡ�û���Ϣ 
	int choose;
	int newpass;
	printf("your id is:\n"+id);
	id=Get_Elem(userid,1);
	printf("your balance is:\n"+balance);
	Get_Elem(balance,1);
	printf("your number of lottery:\n"+number);
	printf("write 1 to change password\n");
	printf("write 2 to buy lottery\n");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("Please write your new password:");
		scanf("%d",&newpass);1
		//��������δ���
		
		printf("change sucess!");
		 
	}
	else if(choose==2)
	{
		//�޸�������Ϣδ��� 
		printf("OK!");
	}
		
}
void admin()
{

	int number;
	PNode lottery = Create_List();
	printf("your id is:\n"+id);                    //����Աid 
	printf("your number of lottery:\n"+number);    //��Ʊ�� 
	
	printf("write 1 to add lottery");
	printf("write 2 to delete lottery");
	printf("write 3 to select lottery");
	int input,lnum;
	scanf("%d",input);
	
	if(input==1)
	{
		int adder;
	    printf("the lottery num:\n",lnum);
	    printf("please input the addnum:",adder);
		scanf("%d",adder);
		
		lnum+=adder;
		printf("����ǰ���ò�Ʊ����Ϊ��",lnum);	
    } 
    if(input==2)
    {
    	int reduce;
    	printf("the lottery num:\n",lnum);
    	printf("������ɾ�����ڲ�Ʊ��Ŀ:",reduce);
    	scanf("%d",reduce);
    	
    	lnum-=reduce;
    	printf("����ǰ��ʣ��Ʊ����Ϊ:",lnum);
	}
	if(input==3)
	{
		printf("select the lottery:");
		
		//��ѯ��Ʊ
	    printf("��ǰ��Ʊ��:\n");
		Go_List(lottery);
	 
	}
}
void register()
{
	int password;
	printf("Please register an account~~\n");
	printf("please write your id:");
	scanf("%d",id);
	printf("please write your password:\n");
	scanf("%d",&password);
	Insert_List(userid,1,id);
	Insert_List(passwd, 1, password);
	Insert_List(balance, 1, 0);
	Insert_List(amount, 1, 0);
	printf("regisetr success!\n");
}
void logout()
{
	char choose1;
    printf("���Ƿ�ѡ��ע���˻�[N/Y]\n");
	scanf("%c",choose1);
	if(choose1 == 'Y'| choose1 == 'y' )
	{
		printf("����ע��~~\n");
		init();
	}
	else if(choose1 == 'N'| choose1 == 'n')
	    if(id==0)
		{
			admin();
		}	
		else
		{
			init();
		}
}


int main()
{
	PNode userid = Create_List();
	PNode passwd = Create_List();
	PNode balance = Create_List();
	PNode amount = Create_List();
	int id; 
	init();
	
	void admin();
	void logout();
	

}

