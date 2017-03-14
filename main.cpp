#pragma once

#include "MRml.h"

using namespace Rad;

int main(void)
{
	rml_document rdoc_read, rdoc_save;

	rdoc_read.open("read.rml");

	// single-line
	{
		rml_node * node = rdoc_read.first_node("single-line");
		const char * value = node->value();

		rdoc_save.append("single-line", value);
	}

	// multi-line
	{
		rml_node * node = rdoc_read.first_node("multi-line");
		const char * value = node->value();

		rdoc_save.append("multi-line", value);
	}

	// sub-node
	{
		rml_node * node = rdoc_read.first_node("sub-node");
		rml_node * child = node->first_node("child");
		const char * value = child->value();

		rdoc_save.append("sub-node", "")->append("child", value);
	}

	rdoc_save.save("save.rml");

	return 0;
}