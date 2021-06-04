

/* Takes the hexacode of the command */
void LCD_command(char command){
    GPIO_PORTA_DATA_R = 0X00;

    // Sends the commands into the data ports (B)
    GPIO_PORTB_DATA_R = command;

    // Sets and resets the enable, because the enable works only in the falling edge
    GPIO_PORTA_DATA_R = 0X80;
    LCD_delay(3);
    GPIO_PORTA_DATA_R = 0X00;

}

/* Takes the hexacode of the data */
void LCD_data(char data){
    // Sets the Rs
    GPIO_PORTA_DATA_R = 0X20;
    // Sends the data into the data ports (B)
    GPIO_PORTB_DATA_R = data;

    GPIO_PORTA_DATA_R |= 0X80;
    LCD_delay(3);
    GPIO_PORTA_DATA_R = 0X00;

}

void LCD_clear(){
    LCD_command(0X01);
}

// Takes a line (0, 1) and a block(0, 15)
void LCD_set_Cursor(int line, int block){
    if(line == 0){
        LCD_command(0X80 + block);
    }
    else if (line == 1){
        LCD_command(0xC0 + block);
    }
}


void LCD_delay(int milliseconds){
    for (int i = 0; i < milliseconds; i++)
    {
        for (int j = 0; j < 3180; j++)
        {
            
        }
        
    }
}
