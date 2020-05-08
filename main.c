#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define temizle system("clear");

typedef struct _node
{
    int data;
    struct _node* next;
}node;

node* make(int sayi)
{
    node* eklenecek = (node*)malloc(sizeof(node));
    eklenecek->data = sayi;
    eklenecek->next = NULL;
    return eklenecek;
}

int pop(node** root)
{
    node* iter = *root;
    if(iter == NULL)
    {
        return 999;
    }
    if(iter->next == NULL)
    {
        int pop_Deger = iter -> data;
        iter = NULL;
        *root = NULL;
        return pop_Deger;
    }
    
    while(iter->next->next != NULL)
    {
        iter = iter -> next;
    }
    node* silinecek = iter -> next;
    int pop_Deger = silinecek -> data;
    iter -> next = NULL;
    free(silinecek);
    return pop_Deger;
}

node* push(node* root, int sayi)
{
    if(root == NULL)
    {
        root = make(sayi);
        return root;
    }
    else{
        node* iter = root;
        while (iter->next != NULL)
        {
            iter = iter -> next;
        }
        node* eklenecek = make(sayi);
        iter -> next = eklenecek;
        return root;
    }
}

void printMenu()
{
    printf("[1] Push \n");
    printf("[2] Pop \n");
    printf("[3] Print Stack \n");
    printf("[4] Çıkış  \n\n");
    printf("Seçiminiz  :  ");
}

void printStack(node* root)
{
    if(root == NULL)
    {
        printf("Stack boş...\n\n");
        return;
    }
    node* iter = root;
    int i = 0;
    while(iter->next != NULL)
    {
        printf("%d. eleman : %d\n", i+1, iter->data);
        iter = iter -> next;
        i++;
    }
    printf("%d. eleman : %d\n", i+1, iter->data);
    
}

int main()
{
    
    node* stack = NULL;
    start:
    temizle
    printMenu();
    int secim;
    scanf("%d", &secim);
    switch (secim)
    {
    case 1:
        temizle
        int sayi;
        geridon:
        
        printf("Pushlamak istediğiniz değeri giriniz(Çıkmak için -1'e basın)   : ");
        scanf("%d", &sayi);
        if(sayi != -1)
        {
            stack = push(stack, sayi);
            
            goto geridon;
        }
        goto start;
        break;
    case 2:
        temizle 
        int sayi2;
        geridon2:

        printf("Pop etmek için 1 geri dönmek için -1'e basın    : ");
        scanf("%d", &sayi2);
        if(sayi2 != -1)
        {
            int popped = pop(&stack);
            if(popped == 999)
            {
                printf("\n\n\nStack içerisinde eleman kalmadı..\n\n");


                fflush(stdin);
                printf("Geri dönmek için bir tuşa basınız.. ");
                getchar();
                goto start;
            }
            printf("Popped : %d\n", popped);
            goto geridon2;
        }
        goto start;
        break;
    case 3:
        temizle
        printStack(stack);

        fflush(stdin);
        printf("\nGeri dönmek için bir tuşa basınız.. ");
        getchar();
        goto start;

        break;
    case 4:
        printf("\nProgramdan çıkılıyor .....\n\n");


        sleep(1);
        break;
    default:
        printf("Hatalı değer girdiniz...\n\n");
        sleep(1);
        goto start;
        break;
    }
}
