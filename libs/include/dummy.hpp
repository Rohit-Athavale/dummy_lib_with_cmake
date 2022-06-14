#ifndef __DUMMY_HPP__
#define __DUMMY_HPP__

// SPDX-License-Identifier : BSD-3-Clause-Attribution

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64)
#ifdef DUMMYL_EXPORTS
#define DUMMYL_API __declspec(dllexport)
#else
#define DUMMYL_API __declspec(dllimport)
#endif /* DUMMYL_EXPORTS  */
#endif /* _WIN32, WIN32 or _WIN64 */

#if defined(__linux__)
#define DUMMYL_API
#endif /* __linux__ */

 class dummy_ops
{
	int add_ops_count;
	int sub_ops_count;
	void inc_add_ops_count(void) { ++add_ops_count; }
	void inc_sub_ops_count(void) { ++sub_ops_count; }
public:
	DUMMYL_API	void reset_ops_count();
	DUMMYL_API	dummy_ops(void) {	reset_ops_count();	}
	DUMMYL_API  int add(const int &a, const int &b);
	DUMMYL_API  int sub(const int &a, const int &b);
	DUMMYL_API  int get_add_ops_count(void) { return add_ops_count; }
	DUMMYL_API  int get_sub_ops_count(void) { return sub_ops_count; }
};

#endif /* __DUMMY_HPP__ */
