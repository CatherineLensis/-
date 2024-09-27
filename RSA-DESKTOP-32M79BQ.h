unsigned int генератор_простых_чисел()
{
	int test;
	while (test < 10);
		{
			unsigned int a = rand() % 65536;
			test = 0;
			if (a == 2) { test = 10;}
			unsigned int b = a % 10;
			if (b != 0 && b != 2 && b != 4 && b != 5 && b != 6 && b != 8)
			{
				for (int i = 0; i < 10; i++)
				{
				
				}
			}
		} 
}