Rails.application.routes.draw do
  #get 'welcome/index'
  #root 'welcome#index'
  
  match '/sums', :to => 'application#sums', :via => [:post]
  match '/filters', :to => 'application#filters', :via => [:post]
  match '/intervals', :to => 'application#intervals', :via => [:post]
  match '/lin', :to => 'application#lin', :via => [:post]
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
