/*
 * BadMatch.h
 *
 *  Created on: 2013��10��25��
 *      Author: �����
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
