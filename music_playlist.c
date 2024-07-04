#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct playlist{
    char title[50];
    struct playlist* next;
};

struct playlist* head = NULL;
void insert_song(){

    struct playlist* newSong = (struct playlist*)malloc(sizeof(struct playlist));
    
    if (newSong == NULL) {
        printf("Memory allocation failed. Exiting.");
        exit(1);
    }
    
    printf("Enter the title of the song: ");
    scanf("%[^\n]", newSong->title);
    newSong->next = NULL;
    
    if (head == NULL) {
        head = newSong;
    } else {
        struct playlist* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    
    printf("Song added successfully.\n");
    
}

void remove_song(){
    struct playlist* q = head;
    struct playlist* p = NULL;
    int num;
    printf("which u want to delete plaese enter it's postion:\n");
    scanf("%d",&num);
    if(num == 0){
        head = head-> next;
        
        free(q);
    }
    else{
        p = head;
        q = NULL;
        for(int i = 0; i < num;i++){

            q = p;
            p = p->next;
        }
        q->next = p->next;
        
        free(p);
        printf("\n song deleted successfully\n");

    }


}
void search_song(){
    struct playlist* temp = head;
    char key[50];
    printf("Enther the name of the song you want to search:");
    fgets(key, sizeof(key),stdin);
    key[strcspn(key, "\n")] = 0;
    while(temp!=NULL){
        if(strcmp(temp->title,key)==0){
            printf("song is present %s\n",key);
        }
        temp = temp->next;
    }
}
void delete_play() {
    struct playlist *current = head;
    struct playlist *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;  
        free(current);           
        current = nextNode; 
    }

    head = NULL;
    printf("Playlist deleted successfully.\n");
}

void view_playlist(){
    if(head == NULL){
        printf("the playlist is empty\n");
    }
    struct playlist* p = head;
    while(p!=NULL){
       
        printf("%s\n",&p->title);
        p = p->next;

    }
}
int main(){
    int input;
    while(1){
    printf("you can :\n 1)Add song \n2)remove song\n 3)search song\n4)delete playlist\n5)view playlist\n");
    printf("enter the number of your choice:");
    scanf("%d",&input);
    getchar();
    
        switch(input)
        {
            case 1: 
             insert_song();
             break;
            case 2:
             remove_song();
             break;
            case 3:
             search_song();
              break;
            case 4:
             delete_play();
             break;
           case 5:
             view_playlist();
             break;
           default:
            printf("wrong choice");
            exit(0);
    
    }
 }
 return 0;
}