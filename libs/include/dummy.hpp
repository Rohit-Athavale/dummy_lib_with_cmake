#ifndef __DUMMY_HPP__
#define __DUMMY_HPP__

// SPDX-License-Identifier : BSD-3-Clause-Attribution

class dummy_ops
{
	int add_ops_count;
	int sub_ops_count;
	void inc_add_ops_count(void) { ++add_ops_count; }
	void inc_sub_ops_count(void) { ++sub_ops_count; }
public:
	void reset_ops_count();
	dummy_ops(void) {	reset_ops_count();	}
	int add(const int &a, const int &b);
	int sub(const int &a, const int &b);
	int get_add_ops_count(void) { return add_ops_count; }
	int get_sub_ops_count(void) { return sub_ops_count; }
};

#endif /* __DUMMY_HPP__ */
