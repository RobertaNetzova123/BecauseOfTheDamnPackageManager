Rails.application.routes.draw do
  resources :rooms
  resources :computers
get '/B_18_Mihaela_Gadzhalovacomputers/', to: 'rooms#index'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
