require 'csv'
input_file = ARGV[0]

result_curl_1 = "528.00"
result_curl_2 = "272"
result_curl_3 = "525.00"
result_curl_4 = "1.000000,0.000000"
result = 0
CSV.foreach(input_file) do |row| 
	result = 0
	current_url = row[5]

	r1 = `curl -s -F \"file=@./B_18_Mihaela_Gadzhalova.csv\" #{current_url}/sums` 
   	r2 = `curl -s -F \"file=@./B_18_Mihaela_Gadzhalova.csv\" #{current_url}/lin_regressions`  
	r3 = `curl -s -F \"file=@./B_18_Mihaela_Gadzhalova.csv\" #{current_url}/filters`
	r4 = `curl -s -F \"file=@./B_18_Mihaela_Gadzhalova.csv\" #{current_url}/intervals`

	if r1 == result_curl_1  && r2== result_curl_2 && r3 == result_curl_3 && r4 == result_curl_4
		result = 1
		puts "#{row[1]}, #{row[2]},  #{row[3]},#{row[4]}, #{result}\n"
	else 
		result = 0
		puts "#{row[1]}, #{row[2]},  #{row[3]},#{row[4]}, #{result}\n"
	end
	
		 
end
