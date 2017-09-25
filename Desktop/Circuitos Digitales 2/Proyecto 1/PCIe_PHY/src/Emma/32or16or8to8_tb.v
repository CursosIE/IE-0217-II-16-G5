module bit8converter_tb(); //Previo a cada prueba se reinicializa el registro en 0000 para mejor visualización en las ondas 
	reg en, dir, s_in;
	wire s_out;
	reg [1:0] mode;
	reg [3:0] d;
	wire [3:0] q;
	registro bit8converter(clk, in, out, mode);
	reg clk = 0;
	always #1 clk = !clk;
	initial begin
		$dumpfile("bit8converter.vcd");
		$dumpvars(0,bit8converter_tb);
		//Pruebas de desplazamientos 
		modo = 2'b10;
		d = 4'b0000;
		en = 1; dir = 0; s_in = 1; #2;
		modo = 2'b00;
		repeat(4) begin //Prueba de desplazamiento hacia la izquierda
			en = 1; dir = 0; s_in = 1; #2;
		end
		
		modo = 2'b10;
		d = 4'b0000;
		en = 1; dir = 0; s_in = 1; #2;
		d = 4'b0101;
		en = 1; dir = 0; s_in = 1; #2;
		modo = 2'b00;
		repeat(4) begin //Prueba de desplazamiento hacia la dercha (inicializado en 0101 para probar la funcionalidad correcta de S_OUT)
			en = 1; dir = 1; s_in = 1; #2;
		end
		
		
		modo = 2'b10;
		d = 4'b0000;
		en = 1; dir = 0; s_in = 1; #2;
		d = 4'b1000;
		en = 1; dir = 0; s_in = 1; #2;
		modo = 2'b01;
		repeat(3) begin //Prueba de desplazamiento circular hacia la izquierda
			en = 1; dir = 0; s_in = 1; #2;
		end
		
		modo = 2'b10;
		d = 4'b0000;
		en = 1; dir = 0; s_in = 1; #2;
		d = 4'b1000;
		en = 1; dir = 0; s_in = 1; #2;
		modo = 2'b01;
		repeat(4) begin //Prueba de desplazamiento circular hacia la derecha
			en = 1; dir = 1; s_in = 1; #2;
		end
		
		//Prueba de carga en paralelo
		
		modo = 2'b10;
		en = 1; dir = 0; s_in = 1; 
		d = 4'bxxxx; #2;
		d = 4'b0000; #2; //0
		d = 4'bxxxx; #2;
		d = 4'b0001; #2; //1
		d = 4'bxxxx; #2;
		d = 4'b0010; #2; //2
		d = 4'bxxxx; #2;
		d = 4'b0011; #2; //3
		d = 4'bxxxx; #2;
		d = 4'b0100; #2; //4
		d = 4'bxxxx; #2;
		d = 4'b0101; #2; //5
		d = 4'bxxxx; #2;
		d = 4'b0110; #2; //6
		d = 4'bxxxx; #2;
		d = 4'b0111; #2; //7
		d = 4'bxxxx; #2;
		d = 4'b1000; #2; //8
		d = 4'bxxxx; #2;
		d = 4'b1001; #2; //9
		d = 4'bxxxx; #2;
		d = 4'b1010; #2; //10
		d = 4'bxxxx; #2;
		d = 4'b1011; #2; //11
		d = 4'bxxxx; #2;
		d = 4'b1100; #2; //12
		d = 4'bxxxx; #2;
		d = 4'b1101; #2; //13
		d = 4'bxxxx; #2;
		d = 4'b1110; #2; //14
		d = 4'bxxxx; #2;
		d = 4'b1111; #2; //15
		
		
		
		$finish;
		
		
	end	
		
endmodule 
