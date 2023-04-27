
#ifndef utiles_H_
#define utiles_H_


#define set_bit(reg,bit)            reg=(reg|(1<<bit))
#define clear_bit(reg,bit)           reg=(reg&(~(1<<bit)))
#define read_bit(reg,bit)              ((reg>>bit)&1)
#define toggel_bit(reg,bit)              reg=reg^(1<<bit)





#endif /* UTILES_H_ */