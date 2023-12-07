// Macro definition for setting a bit in a variable
#define SET_BIT(VAR, BIT_NO)          (VAR |= (1 << BIT_NO))
// Macro definition for clearing a bit in a variable
#define CLR_BIT(VAR, BIT_NO)          (VAR &= ~(1 << BIT_NO))
// Macro definition for getting the value of a bit in a variable
#define GET_BIT(VAR, BIT_NO)          ((VAR >> BIT_NO) & 1)