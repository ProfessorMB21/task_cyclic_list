#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

struct node_t
{
	int data;
	node_t* next = nullptr;
public:
	node_t() : data(0) {}
	node_t(int _data) : data(_data) {}
};

struct list_t
{
	node_t* head = nullptr;
public:
	void add(int _data)
	{
		node_t* new_node = new node_t(_data);
		if (this->head == nullptr)
		{
			this->head = new_node;
		}
		else
		{
			new_node->next = this->head;
			this->head = new_node;
		}
	}
	void free()
	{
		while (this->head)
		{
			auto* temp = this->head->next;
			delete this->head;
			this->head = temp;
		}
	}
	/*/
	bool is_cyclic()
	{
		if (!this->head || !this->head->next) return false;

		node_t* slow_node = this->head;
		node_t* fast_node = slow_node->next;

		while (slow_node != fast_node && slow_node->next != this->head)
		{
			slow_node = slow_node->next;
			fast_node = slow_node->next->next;

			if (slow_node == fast_node)
				return true; // list is cyclic
		}
		if (slow_node != fast_node)
			return false;

		slow_node = this->head; // reset slow_node pointer
		while (slow_node != fast_node)
		{
			slow_node = slow_node->next;
			fast_node = fast_node->next;
			if (slow_node == fast_node) return true;
		}

		return false; //otherwise, list is not cyclic
	}
	*/
	bool is_cyclic()
	{
		node_t* node1, * node2, * node3;
		node1 = node2 = node3 = this->head;

		while (node1)
		{
			node2 = node3->next;
			node3 = node2->next;
			if (node1 == node2 || node1 == node3)
				return true;
			node1 = node1->next;
		}
		return false;
	}

	void toHead()
	{
		node_t* temp = this->head;
		while (temp->next)
			temp = temp->next;
		temp->next = this->head;
	}
};
