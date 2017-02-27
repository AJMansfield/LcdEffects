/**
 *	@file	Cache.h
 *	@brief	A cache implementation, used for caching characters by LcdEffects.
 *	@author	Anson Mansfield
 *	@date 	2017-02-26
 */

#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>

/**
 *	@brief	A cache implementation, used for LcdEffects' character cache.
 *	
 *	This class was not designed for general use, and is difficult to use correctly,
 *	but feel free to use it if you can figure it out.
 *	
 *	Of note is that this cache _only stores keys_, and leaves generating and storing
 *	(or not storing) the corresponding values (e.g. in an array or other structure)
 *	to the user.
 */
template<typename element_t, typename size_t = uint8_t, size_t size = 0, typename age_t = uint8_t>
class Cache {
public:
	struct report_t {
		size_t index;
		bool old;
	};

	report_t get(element_t&);
	void setRange(size_t first, size_t last);
	void clear(element_t& zero);

private:

	element_t cache[size];

	age_t used[size];
	age_t use = 0;

	size_t begin = 0;
	size_t end = size;

	size_t find(element_t&);
	size_t oldest();
};


template<typename element_t, typename size_t, size_t size, typename age_t>
typename Cache<element_t,size_t,size,age_t>::report_t Cache<element_t,size_t,size,age_t>::get(element_t& e){
	Cache<element_t,size_t,size,age_t>::report_t result;
	size_t i;

	i = find(e);
	if(i == end){
		i = oldest();
		cache[i] = e;
		result.old = false;
	} else {
		result.old = true;
	}
	result.index = i;
	used[i] = ++use;

	return result;
}

template<typename element_t, typename size_t, size_t size, typename age_t>
void Cache<element_t,size_t,size,age_t>::setRange(size_t first, size_t last){
	begin = first;
	end = last;
}

template<typename element_t, typename size_t, size_t size, typename age_t>
void Cache<element_t,size_t,size,age_t>::clear(element_t& zero){
	use = 0;
	for(size_t i = 0; i < size; i++){
		used[i] = 0;
		cache[i] = zero;
	}
}

template<typename element_t, typename size_t, size_t size, typename age_t>
size_t Cache<element_t,size_t,size,age_t>::find(element_t& e){

	for(size_t i = begin; i < end; i++){
		if(cache[i] == e){
			return i;
		}
	}

	
	return end;
}

template<typename element_t, typename size_t, size_t size, typename age_t>
size_t Cache<element_t,size_t,size,age_t>::oldest(){
	size_t best = 0;
	age_t age = 0;
	for(size_t i = begin; i < end; i++){
		if(use - used[i] > age){
			age = use - used[i];
			best = i;
		}
	}
	return best;
}

#endif