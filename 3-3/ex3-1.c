/**
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 */

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int l, h, mid;

	l = 0;
	h = n - 1;

	for (mid = (l+h) / 2; l <= h && x != v[mid]; mid = (l+h) / 2) {
		if (x < v[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
    if (x == v[mid])
        return mid;
	return -1;	/* no match */
}
