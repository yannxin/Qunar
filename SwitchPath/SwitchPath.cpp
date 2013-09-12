#include "stdafx.h"

void SwitchPath(string &inPath, string &outPath)
{
	if (inPath.empty())
		return;
	stack<string> path1, path2;
	string in = inPath;
	string temp;
	string slash = "/";

	size_t preSlash  = in.find(slash, 0);
	size_t postSlash = preSlash;

	while(postSlash < in.length())
	{
		preSlash = postSlash;
		postSlash = in.find(slash, preSlash+1);
		if (postSlash < in.length())
		{
			temp.assign(in.begin()+preSlash+1, in.begin()+postSlash);
			if (temp == "..")
			{
				if (path1.empty())
				{
					outPath.clear();
					return;
				}
				else
					path1.pop();
			}
			else if (temp != "." && !temp.empty())
				path1.push(temp);
		}
	}

	while (!path1.empty())
	{
		temp = path1.top();
		path2.push(temp);
		path1.pop();
	}

	while (!path2.empty())
	{
		temp = path2.top();
		outPath = outPath + "/" + temp;
		path2.pop();
	}
//	puts(outPath.c_str());
}