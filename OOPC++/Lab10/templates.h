#pragma once

template<typename T> void printCont(T obj) {
	std::cout << obj << std::endl;
}

template<typename T> void changeContElm(T& obj) {
	obj += 2;
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