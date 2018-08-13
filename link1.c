#include<stdio.h>
#include<malloc.h>
struct utl{
        int val;
        struct utl *next;
};
struct utl *ptr=NULL,*head,*start;
void insert(){
        int num;
        printf("Enter The Number");
        scanf("%d",&num);
        if(ptr==NULL){
                ptr=(struct utl*)malloc(sizeof(struct utl));
                ptr->val=num;
                ptr->next=NULL;
                head=ptr;
                start=head;
        }
        else{
                ptr->next=(struct utl*)malloc(sizeof(struct utl));
                ptr=ptr->next;
                ptr->val=num;
                ptr->next=NULL;
        }
}
void insert_head(){
        int n;
        printf("Enter The Number: ");
        scanf("%d",&n);
        struct utl *temp;
        temp=(struct utl *)malloc(sizeof(struct utl));
        temp->val=n;
        temp->next=start;
        start=temp;
        head=start;
}
void traverse(){
            struct utl *node=head;
            while(node!=NULL){
                    printf("%d\n",node->val);
                    node=node->next;
            }
            head=start;
}

void insert_last(){
            int n;
            printf("Enter The Number: ");
            scanf("%d",&n);
            struct utl *temp;
            while(head->next!=NULL){
                    head=head->next;
            }
            temp=(struct utl *)malloc(sizeof(struct utl));
            temp->val=n;
            temp->next=NULL;
            head->next=temp;
            head=start;
}
void insert_at_any_place(){
    printf("Enter The Index You Want To Insert To:");
    int n,n1;
    scanf("%d",&n);
  printf("Enter The Number: ");
  scanf("%d",&n1);
    struct utl *temp,*temp2=head;
    temp=(struct utl *)malloc(sizeof(struct utl));
    temp->val=n1;
    while(n>0){
                temp2=head;
                head=head->next;
                n--;
    }
    temp2->next=temp;
    temp->next=head;
    
    head=start;
}
int main(){
        char ch;
        int choice;
        do{
                printf("Enter 1 to Insert\n");
                printf("Enter 2 to Traverse\n");
                printf("Enter 3 to Insert in Beginning\n");
                printf("Enter 4 to Insert at Last\n");
                printf("Enter 5 to Insert at Any Place\n");
            //  printf("Enter 1 to Insert\n");
            //  printf("Enter 1 to Insert\n");
                scanf("%d",&choice);
                switch(choice){
                    case 1:insert();
                                 break;
                    case 2:traverse();
                        break;
                    case 3:insert_head();
                        break;
                    case 4:insert_last();
                        break;
                    case 5:insert_at_any_place();
                        break;
                    default:printf("You Entered Wrong\n");
										break;
                }       
                printf("Do You Wish to Exit? Press N\n");
              scanf(" %c",&ch);
                
        }
        while(ch!='n' || ch!='N');
}
