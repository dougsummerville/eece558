void entry_point( void ); 

void * const  __attribute__((section(".vector_table"))) vector_table[] =  
{
	(void *)0x20082000, 
	&entry_point	    
};

unsigned const __attribute__((section(".boot_block"))) bootblock[] =  
{
	0xFFFFDED3, 
	0x10210142, 
	0x000001FF, 
	0x00000000, 
	0xAB123579  
};

void entry_point( void )
{
	
	*(unsigned volatile *)0x40020000 &= 0xFFFFFDBF;
	while((*(unsigned volatile *)0x40020008 & 0x00000240) != 0x00000240)
		continue;
	
	*(unsigned volatile *)0x40038068 = 0;
	*(unsigned volatile *)0x400280CC = 5;
	
	*(unsigned volatile *)0xd0000038 = 0x02000000;
	
	while(1) {
		
		*(unsigned volatile *)0xd0000028 = 0x02000000;
		
		for( volatile unsigned int i=0; i<120000; i++ )
			continue;
	}
}
