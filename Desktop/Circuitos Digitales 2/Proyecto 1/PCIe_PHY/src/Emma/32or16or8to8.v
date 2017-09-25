module bit8converter(clk, in, out, mode)
	input clk;
	input [32:0] reg in;
	input [1:0] mode;
	output reg  [8:0] out;
	reg [1:0] selector;
	selector=2'b00;
if(mode==2'b00) begin
	always@(posedge clk)begin
		in<=out[7:0]
		end
	end

else if(mode==2'b01)begin
	always@(posedge clk)begin
		if(selector==2'b00) begin
			in<=out[7:0]
			selector==2'b01
			end
		else if(selector==2'b01) begin
			in<=out[15:8]
			selector==2'b00
			end
		end
	end
	
else if(mode==2'b10)begin
	always@(posedge clk)begin
		if(selector==2'b00) begin
			in<=out[7:0]
			selector==2'b01
			end
		else if(selector==2'b01) begin
			in<=out[15:8]
			selector==2'b10
			end
		else if(selector==2'b10) begin
			in<=out[23:16]
			selector==2'b11
			end
		else if(selector==2'b11) begin
			in<=out[31:24]
			selector==2'b00
			end
		end
	end
