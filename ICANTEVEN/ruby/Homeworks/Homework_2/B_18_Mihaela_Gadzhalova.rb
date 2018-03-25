require 'csv'

file = ARGV[0]
fixture = ARGV[1]
result = 0

CSV.foreach(file, :headers => true) do |row|

	heroku_url = row[5]
	#p row[1] + ', ' + row[2] + ', ' + row[3] + ', ' + row[4]  
	
	r1 = `curl -s -F "file=@./#{fixture}" #{heroku_url}/sums`
	r2 = `curl -s -F "file=@./#{fixture}" #{heroku_url}/filters`
	r3 = `curl -s -F "file=@./#{fixture}" #{heroku_url}/intervals`
	r4 = `curl -s -F "file=@./#{fixture}" #{heroku_url}/lin_regressions`

	if(row[1] != nil && row[2] != nil && row[3] != nil && row[4] != nil && row[5] != nil && row[6] != nil)
		if(r1 == "126.00" && r2 == "40.00" && r3 == "118.00" && r4 == "0.014006,3.347899")
		
			result = 1
		else
		
			result = 0
		end

		puts "#{row[1]}, #{row[2]}, #{row[3]}, #{row[4]}, #{result}"
		#puts row[1] + ', ' + row[2] + ', ' + row[3] + ', ' + row[4] + ', ' + result
	end
	
end
