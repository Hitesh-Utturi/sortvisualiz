#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
using namespace std;
void draw_state(vector<int>&v,SDL_Renderer* renderer,unsigned int red,unsigned int blue)
{
    int index=0;
    for(i:v)
    {
        if(index==red)
        {
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
        }
        else if(index==blue)
        {
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
        SDL_RenderDrawLine(renderer,index,99,index,,i);
        index+=1;
        
    }
}
int main()
{
    random_device rd;
    uniform_int_distribution d(1,99);
    vector<int>v;
    for(int i=0;i<100;i++)
    {
        v.push_back(d(rd));
    }
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer=nullptr;
    SDL_CreateWindowAndRendered(100*10,100*10,0,&window,&renderer);
    SDL_RenderSetScale(renderer,10,10);
    for(unsigned int i=0;i<v.size();i++)
    {
        for(unsigned int j=1;j<v.size();j++)
        {
            if(v[j]<v[i])
            {
                swap(v[j],v[i]);
            }
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_RenderClear(renderer);
            draw_state(v,renderer,i,j);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
    for(int i:v)
    {
        cout<<i<<" ";
    }
    if(std::ranges::is_sorted(v))
    {
        cout<<"\nsorted\n";
    }
}
