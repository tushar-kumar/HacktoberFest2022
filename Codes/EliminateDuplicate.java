package linkedlist;

import java.util.Scanner;

public class EliminateDuplicate {
	
	public static Node<Integer> eliminate(Node<Integer> head){
		
		Node<Integer> temp = head;
		
		while(temp.next != null) {
			if(temp.data == temp.next.data) {
				temp.next = temp.next.next;
			}
			else temp = temp.next;
		}
		return head;
	}
	
	public static Node<Integer> takeInput(){
		Node<Integer> head = null, tail = null;
		Scanner sc = new Scanner(System.in);
		int data = sc.nextInt();
		
		while(data != -1) {
			Node<Integer> newNode = new Node<Integer>(data);
			if(head == null) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail.next = newNode;
				tail = newNode;
			}
			data = sc.nextInt();
		}
		sc.close();
		return head;
	}
	
	public static void print(Node<Integer> head) {
		while(head != null) {
			System.out.print(head.data+" ");
			head = head.next;
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node<Integer> head = takeInput();
		head = eliminate(head);
		print(head);

	}

}
