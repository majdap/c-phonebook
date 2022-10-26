#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

/*Create phone book entry structure.*/
typedef struct pbentry {   
    char name[50];  
    char phone[20];
    char address[30];
}Entry;


/*Create tree node structure.*/
struct tree_node {    
    Entry data;     
    struct tree_node *left;     
    struct tree_node *right;
};   


/*Function Prototypes*/
struct tree_node *name_insert(struct tree_node *p, Entry e); 
struct tree_node *num_insert(struct tree_node *p, Entry e); 

struct tree_node *create_node (struct tree_node *q, struct tree_node *r, Entry e); 
struct tree_node *delete_name (struct tree_node *p, char n[]);
struct tree_node *delete_num (struct tree_node *p, char n[]);
struct tree_node *findmin(struct tree_node *p);

char* name_search(struct tree_node *p, char n[]);
void num_search(struct tree_node *p, char n[]);

void print_tree(struct tree_node *p);



// Main function
int main(void)
{
    int option = 0; /*Variable for option selection.*/    
    Entry e;  /*phone book entry*/

    struct tree_node *pname = NULL; /*name tree node*/    
    struct tree_node *pnum = NULL; /*num tree node*/

    char name[50]; /* Used for deletions and searching */
    char num[20];
    // char temp; // used to clear input stream for space delimitted inputs

    /*Return to menu after each instruction until the user quits.*/    
    while (option != 6) {

    /*Show user the option menu.*/        
        printf("\nMENU\n");         
        printf("1. Add\n");         
        printf("2. Delete\n");                 
        printf("3. Name Search\n");
        printf("4. Number Search\n");         
        printf("5. List\n");         
        printf("6. Quit\n");         

        /*Get option from the user.*/        
        printf("\nPlease select an option: ");         
        scanf("%d", &option);   

        /*If option is 1 (Add):*/    
        if (option == 1) {            

            fflush(stdin);
            printf("Please enter the name: ");             
            scanf("%[^\n]", e.name);

            fflush(stdin);
            printf("Please enter the phone number: ");             
            scanf("%[^\n]", e.phone);             

            fflush(stdin);
            printf("Please enter the address: ");             
            scanf("%[^\n]", e.address);

            /*Insert name*/           
            pname = name_insert(pname, e);

            /*Insert number*/        
            pnum = num_insert(pnum, e);

            /*Confirm node creation.*/            
            printf("Contact for %s added successfully.\n", e.name);
        }


        /*If option is 2 (Delete):*/                
        else if (option == 2) {
            fflush(stdin);
            printf("Please enter the name: "); 
            scanf("%[^\n]", name);

            fflush(stdin);
            printf("Please enter the number: "); 
            scanf("%[^\n]", num);

            /*Delete the num from num tree*/
            pnum = delete_num(pnum, num);

            /*Delete a node from name tree*/ 
            pname = delete_name(pname, name);
        }


        /*If option is 3 (Name Search):*/                
        else if (option == 3) {          
            fflush(stdin);
            printf("Please enter the name: ");             
            scanf("%[^\n]", name); 

            /*Search for a node.*/            
            name_search(pname, name);         
        }


        /*If option is 4 (Number Search):*/                
        else if (option == 4) {          
            fflush(stdin);
            printf("Please enter the number: ");             
            scanf("%[^\n]", num);

            /*Search for a node.*/            
            num_search(pnum, num);         
        }


        /*If option is 5 (List):*/              
        else if (option == 5) {     
            print_tree(pname); // print name tree nodes   
        }   


        /*If option is 6 (Quit):*/              
        else if (option == 6) {
            printf("Exiting.\n");           
            break; /*End the program.*/       
        } 


        /*If the user does not select an existing option.*/            
        else {            
            /*Print error message.*/            
            printf("That option does not exist. Exiting. \n\n");
            break; // user may have entered character - can't assign to int      
        } 

    // End of option while loop  
    }    
        
    // End of function
    return 0; 
}



/*Adds a node to the tree.*/
struct tree_node *num_insert(struct tree_node *p, Entry e) 
{     
    /*If there is no root:*/ 
    if (p == NULL) {
        /*Create a root.*/       
        p = create_node(NULL, NULL, e);    
    }

    /*If there is a root, and the entry belongs before the root:*/    
    else if (strcmp(e.phone, p->data.phone) < 0) {      
        /*Add before root.*/       
        p->left = num_insert(p->left, e);     
    }

    /*If there is a root, and the entry belongs after the root:*/    
    else if (strcmp(e.phone, p->data.phone) > 0) {    
        /*Add after root.*/    
        p->right = num_insert(p->right, e);   
    }

    /*Return revised tree.*/ 
    return p; 
}



/*Adds a node to the tree.*/
struct tree_node *name_insert(struct tree_node *p, Entry e) 
{     
    /*If there is no root:*/ 
    if (p == NULL) {       
        /*Create a root.*/       
        p = create_node(NULL, NULL, e);    
    }

    /*If there is a root, and the entry belongs before the root:*/    
    else if (strcmp(e.name, p->data.name) < 0) {      
        /*Add before root.*/       
        p->left = name_insert(p->left, e);     
    }

    /*If there is a root, and the entry belongs after the root:*/    
    else if (strcmp(e.name, p->data.name) > 0) {    
        /*Add after root.*/    
        p->right = name_insert(p->right, e);   
    }

    /*Return revised tree.*/ 
    return p; 
}



/*Creates a new node.*/
struct tree_node *create_node (struct tree_node *q, struct tree_node *r, Entry e)
{     
    struct tree_node* newnode;     
    newnode = (struct tree_node*)(malloc(sizeof(struct tree_node)));     
    newnode->data = e;     
    newnode->left = q;     
    newnode->right = r;     
    return newnode;
}


struct tree_node *delete_name(struct tree_node *p, char n[])
{
    // empty node
    if (p == NULL) {
        return NULL;
    }

    /*If name is before root:*/   
    if (strcmp(n, p->data.name) < 0) {        
        
        /*Delete from before root.*/       
        p->left = delete_name(p->left, n);
    }

    /*if name is after root:*/   
    else if (strcmp(n, p->data.name) > 0) {  

        /*Delete from after root.*/       
        p->right = delete_name(p->right, n);
    }

    // node to be deleted
    else {
        // node with one or no child
        if (p->left == NULL) {
            struct tree_node *tmp = p->right;
            free(p);
            return tmp;
        }

        else if (p->right == NULL) {
            struct tree_node *tmp = p->left;
            free(p);
            return tmp;
        }

        // a node with two children
        // get the inorder successor - smallest right tree
        struct tree_node *tmp = findmin(p->right);

        // copy inorder successor and copy to node
        p->data = tmp->data;

        // delete the inorder successor
        p->right = delete_name(p->right, tmp->data.name);
    }
    return p;
}



struct tree_node *delete_num(struct tree_node *p, char n[])
{
    // empty node
    if (p == NULL) {
        return NULL;
    }

    /*if number is before root:*/   
    if (strcmp(n, p->data.phone) < 0) {        
        
        /*Delete from before root.*/       
        p->left = delete_num(p->left, n);    
    }

    /*If number is after root:*/   
    else if (strcmp(n, p->data.phone) > 0) {  

        /*Delete from after root.*/       
        p->right = delete_num(p->right, n);    
    }

    // node to be deleted
    else {
        // node with one or no child
        if (p->left == NULL) {
            struct tree_node *tmp = p->right;
            free(p);
            return tmp;
        }

        else if (p->right == NULL) {
            struct tree_node *tmp = p->left;
            free(p);
            return tmp;
        }

        // a node with two children
        // get the inorder successor - smallest right tree
        struct tree_node *tmp = findmin(p->right);

        // copy inorder successor and copy to node
        p->data = tmp->data;

        // delete the inorder successor
        p->right = delete_num(p->right, tmp->data.phone);
    }
    return p;
}



struct tree_node *findmin(struct tree_node *p)
{
    struct tree_node *curr = p;

    /*find the leftmost node in tree*/
    while (curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}



/*Searches for a node and retrieves data.*/
char* name_search(struct tree_node *p, char n[]) 
{    
    /*If entry is before root:*/    
    if (p == NULL) {
        return "Record could not be found\n";
    }

    else if (strcmp(n, p->data.name) < 0) {         
        /*Check before root.*/
        name_search(p->left, n);
    }

    /*If entry is after root:*/    
    else if (strcmp(n, p->data.name) > 0) {
        /*Check after root.*/       
        name_search(p->right, n);
    }

    /*If entry is located:*/    
    else if (strcmp(n, p->data.name) == 0) {
        printf("%s, %s, %s\n\n", p->data.name, p->data.phone, p->data.address); /*Print out*/
        // printf("The associated number is %s\n", p->data.phone);
        return p->data.phone;
    }

    return "Record could not be found\n";
}



/*Searches for a node and retrieves data.*/
void num_search(struct tree_node *p, char n[]) 
{    
    /*If entry is before root:*/    
    if (p == NULL) {
        printf("Record could not be found\n");
        return;
    }

    else if (strcmp(n, p->data.phone) < 0) {         
        /*Check before root.*/
        num_search(p->left, n);
    }

    /*If entry is after root:*/    
    else if (strcmp(n, p->data.phone) > 0) {
        /*Check after root.*/       
        num_search(p->right, n);
    }

    /*If entry is located:*/    
    else if (strcmp(n, p->data.phone) == 0) {
        printf("%s, %s, %s\n\n", p->data.name, p->data.phone, p->data.address); /*Print out*/
    }

    /*If entry is not found:*/   
    else {
        /*Error.*/       
        printf("Record could not be found.\n");
    }
}



/*Prints contents of tree.*/
void print_tree(struct tree_node *p) {   
    /*if tree has nodes:*/    
    if (p != NULL){         
        
        /*Print node data.*/        
        print_tree(p->left);        
        printf("%s, %s, %s\n", p->data.name, p->data.phone, p->data.address);        
        print_tree(p->right);
    }
}
