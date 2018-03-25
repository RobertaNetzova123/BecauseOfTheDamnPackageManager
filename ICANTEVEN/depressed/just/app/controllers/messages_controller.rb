require 'json'
class MessagesController < ApplicationController
	def show
    		@message = Message.find(params[:id])
  	end

  	def new
    		@message = Message.new
  	end

  	def create
		if request.content_type =~ /xml/
      message_hash = Hash.from_xml(request.body.read)

      params[:message] = {"content" => message_hash["message"]}

      @message = Message.create(parameters)

      url = '<?xml version = "1.0" encoding = "UTF-8" standalone ="yes"?>' + 
            "<url>" + 
              messages_url + '/' + @message.id.to_s + 
            "</url>"

      render :xml => url
    else
      respond_to do |f|
          f.json {
            params[:message] = {"content" => params[:message]}

            @message = Message.create(parameters)

            url = {"url" => messages_url + "/" + @message.id.to_s}

            render :json => url.to_json
          }

          f.html {
            @message = Message.create(parameters)

            render :get
          }
      end
end

  	end
 
  	def get
    
  	end

private
  	def parameters
    		params.require(:message).permit(:content)
  	end
end
