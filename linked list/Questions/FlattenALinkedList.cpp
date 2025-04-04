// this is the question of only linkedList not the leetcode question

//approach one (Reute force)

// using array

arr=[]  temp=head

while(temp!=NULL){
  t2=temp
  while(t2!=NULL){
  arr.add(t2->val)
  t2=t2->child;
  }
  temp=temp->next;

  convert function (){
  if(arr.size()==0)  return arr
  head=new Node(arr[0])
  temp=head;
  for(int i->n-1){
  newNode = new Node(arr[i]);
  temp->child=newNode;
  temp=temp->child;
  }
  return head;
  }
}   t.c(nxm) s.c(nxm)x2

//approach two (merging the vertical sorted lL APPROACH)

MergeLists(list1,list2){
    dummyNode= new Node(-1);
    res=dummyNode;
    while(list1!=NULL && list2!=NULL){
        
    }
}

