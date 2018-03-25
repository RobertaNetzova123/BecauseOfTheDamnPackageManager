Rails.application.routes.draw do
	
	get 'messages/new'  
	resources :messages
	root 'messages#new'  
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
