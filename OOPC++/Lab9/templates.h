#pragma once


template<typename T> void printInfoSPQ(T cont) {
	while (!cont.empty()) {
		std::cout << cont.top() << " ";
		cont.pop();
	}
	std::cout << std::endl;	
}

template<typename T> void printInfoQ(T cont) {
	while (!cont.empty()) {
		std::cout << cont.front() << std::endl;
		cont.pop();
	}
	std::cout << std::endl;
}

template<typename T> void printInfoVLD(const T& cont) {
	//std::cout << "Container's type: " << typeid(cont).name() << std::endl;
	T::const_iterator itf = cont.begin();
	T::const_iterator itl = cont.end();
	while (itf != itl) {
		std::cout << *itf << " ";
		++itf;
	}
	std::cout << std::endl;
}

template<typename T> void printInfoMap(const T& cont) {
	//std::cout << "Container's type: " << typeid(cont).name() << std::endl;
	T::const_iterator itf = cont.begin();
	T::const_iterator itl = cont.end();
	while (itf != itl) {
		std::cout << (*itf).first << "\t" << itf->second << std::endl;
		++itf;
	}
	std::cout << std::endl;
}

template<typename T> void printInfoMap1(const T& cont) {
	//std::cout << "Container's type: " << typeid(cont).name() << std::endl;
	T::const_iterator itf = cont.begin();
	T::const_iterator itl = cont.end();
	while (itf != itl) {
		std::cout << (*itf).first << "\t";
		printInfoVLD(itf->second);
		++itf;
	}
	std::cout << std::endl;
}

template<typename T> void printInfoMMap (T itf, T itl) {
	//std::cout << "Container's type: " << typeid(cont).name() << std::endl;
	//T::const_iterator itf = cont.begin();
	//T::const_iterator itl = cont.end();
	std::cout << (*itf).first << "\t";
	while (itf != itl) {
		std::cout << itf->second << " ";
		++itf;
	}
	std::cout << std::endl;
}

template<typename T> void printInfoVLDreverse(const T& cont) {
	//std::cout << "Container's type: " << typeid(cont).name() << std::endl;
	T::const_reverse_iterator itf = cont.rbegin();
	T::const_reverse_iterator itl = cont.rend();
	while (itf != itl) {
		std::cout << *itf << " ";
		++itf;
	}
	std::cout << std::endl;
}