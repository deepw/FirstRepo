
array_add_one (char *num, char *result)
{
	int i = n-1;
	int carry = 1;
	while (num[decimal] != '.' && num[decimal] != '\0') {
		decimal++;
	}
	i = decimal;
	while (num[i] != '\0') {
		result[i] = num[i];
		i++;
	}
	i = decimal-1;
	while (i>=0) {
		sum = arr[i] + carry;
		result[i+1] = sum%10;
		carry = sum/10;
		i--;
	}
	if (carry) {
		result[i+1] = 1;
	} else {
		result[i+1] = 0;
	}
}

