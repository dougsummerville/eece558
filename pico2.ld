MEMORY
{
  FLASH  (rx)    : ORIGIN = 0x10000000,  LENGTH = 4M 
}

/*Map sections to memory*/
SECTIONS
{
	.text : {
		*(.vector_table*)
		*(.boot_block*)
		*(.text*)
	} > FLASH
}
    
