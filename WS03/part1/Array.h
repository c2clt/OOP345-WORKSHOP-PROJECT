
#ifndef SDDS_ARRAY_H__
#define SDDS_ARRAY_H__

namespace sdds {
	template <typename T>
	class Array {
		T* m_data = nullptr;
		unsigned int m_size;
	public:
		Array(unsigned int size = 1);
		Array(const Array<T>& src);
		Array<T>& operator=(const Array<T>& src);
		Array(Array<T>&& src);
		Array<T>& operator=(Array<T>&& src);
		unsigned int size() const;
		void resize(unsigned int newsize);
		T& at(unsigned int idx);
		T& operator[](unsigned int idx);
		virtual ~Array();
	};

	template <typename T>
	Array<T>::Array(unsigned int size) : m_size(size) {
		if (m_size == 0) m_size = 1;
		m_data = new T[m_size];
	}
	
	template <typename T>
	unsigned int Array<T>::size() const {
		return m_size;
	}
	template <typename T>
	void Array<T>::resize(unsigned int newsize) {
		unsigned int i;
		if (newsize == 0) newsize = 1;
		T* newData = new T[newsize];
		for (i = 0; i < m_size && i < newsize; i++) {
			newData[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_size = newsize;
	}

	template <typename T>
	T& Array<T>::at(unsigned int idx) {
		if (idx >= m_size) {
			resize(idx + 1);
		}
		return m_data[idx];
	}
	template <typename T>
	T& Array<T>::operator[](unsigned int idx) {
		return at(idx);
	}

	template <typename T>
	Array<T>::~Array() {
		delete[] m_data;
		m_data = nullptr;
	}

	template <typename T>
	Array<T>::Array(const Array<T>& src) {
		operator=(src);
	}
	template <typename T>
	Array<T>& Array<T>::operator=(const Array<T>& src) {
		if (this != &src) {
			delete[] m_data;
			m_data = new T[m_size = src.size()];
			for (unsigned int i = 0; i < m_size; i++) {
				m_data = src.m_data;
			}
		}

		return *this;
	}

	template <typename T>
	Array<T>::Array(Array<T>&& src) {
		operator=(std::move(src));
	}
	template <typename T>
	Array<T>& Array<T>::operator=(Array<T>&& src) {
		if (this != &src) {
			delete[] m_data;
			m_data = src.m_data;
			src.m_data = new T[1];
			m_size = src.m_size;
			src.m_size = 1;
		}

		return *this;
	}
}
#endif
