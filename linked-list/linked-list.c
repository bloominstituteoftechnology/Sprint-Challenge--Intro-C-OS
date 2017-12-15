struct LinkedList {
  int data;
  struct LinkedList *next;
};

typedef struct LinkedList *node;
struct LinkedList

node createNode() {
  node temp;
  temp = (node)malloc(sizeof(struct LinkedList));
malloc()
  temp ->next = NULL;
  return temp;
  
}

new_node()

append_node()

int main(void) {
}


//tried following along with a tutorial for this- I didn't want to blindly write the code without understanding what is going on
//went through multiple tutorials before I found one that I liked- unfortunately I ran out of time for implementation

//I have a fundamental weakness with Data Structures in general and definitely need to work on them A LOT more. Adding in C is just another challenge to add to it, a challenge that I have been shying away from
//for most of the week- I'm ashamed to say. 

//Hopefully the other part of this challenge was sufficient because I am extremely dissapointed in my performance with this portion of the challenge. Trying to do better