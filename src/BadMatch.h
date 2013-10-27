/*
 * BadMatch.h
 *
 *  Created on: 2013年10月25日
 *      Author: 李恒毅
 */

#ifndef BADMATCH_H_
#define BADMATCH_H_

#include <exception>

class bad_match : public std::exception
{
public:
	bad_match():std::exception() {}
};


#endif /* BADMATCH_H_ */
