#pragma once
#include<memory>
#include<cmath>
#define TOR 0.000001

namespace container {
	template <typename T>
	struct Node {
		T m_data;
		std::shared_ptr<Node> m_next;

		Node(const T& data) : m_data(data), m_next(nullptr) {

		}
	};

	template <typename T>
	class List {
	private:
		std::shared_ptr<Node<T>> m_head;
		std::shared_ptr<Node<T>> m_current;
		int m_length;
	public:
		List() : m_head(nullptr), m_current(nullptr), m_length(0) {

		}

		void clean() {
			while (m_head) {
				m_head = m_head->m_next;
			}
		}
		~List() {
			clean();
		}
		void append(const T& data) {
			auto temp_node = std::make_shared<Node<T>>(data);
			if (!m_head) {
				m_current = temp_node;
				m_head = temp_node;
			}
			else {
				m_current->m_next = temp_node;
				m_current = temp_node;
			}
			m_length++;
		}

		bool search(const T& data) const {
			std::shared_ptr<Node<T>> temp_node;
			temp_node = m_head;
			bool notFound = true;
			while (notFound && temp_node) {
				if (abs(temp_node->m_data - data) <= TOR) {
					notFound = false;
					return true;
				}
				else {
					temp_node = temp_node->m_next;
				}
			}
			return false;
		}

		void remove(const T& data) {

		}

		int len() const {
			return m_length;
		}

		void print() {
			if (!m_length) {
				std::cout << "Empty list" << std::endl;
			}
			else {
				std::shared_ptr<Node<T>> print_list;
				print_list = m_head;
				while (print_list) {
					std::cout << print_list->m_data << " ";
					print_list = print_list->m_next;
				}
				std::cout << std::endl;
			}
		}
	};
}
