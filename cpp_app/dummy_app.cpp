#include <iostream>

#include "../libs/include/dummy.hpp"

using namespace std;

// SPDX-License-Identifier : BSD-3-Clause-Attribution

int main(void)
{
	dummy_ops dop;
	for (int i = 1, j = 11; i <= 10 && j <=20; i++, j++) {
		cout << j << " + " << i << " = " << dop.add(j,i) << "\t";
		cout << j << " - " << i << " = " << dop.sub(j,i) << endl;
	}
	cout << " add ops performed = " << dop.get_add_ops_count() << endl;
	cout << " sub ops performed = " << dop.get_sub_ops_count() << endl;
	return 0;
}
