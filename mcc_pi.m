function [znotraj, izven] = mcc_pi(N)
    % Generiramo N naključnih točk znotraj kvadrata [0, 1] x [0, 1]
    x = rand(N, 1);
    y = rand(N, 1);
    
    % Preverimo, ali so točke znotraj enotskega kroga
    radii = x.^2 + y.^2;
    znotraj_kroga = radii <= 1;
    
    znotraj = [x(znotraj_kroga), y(znotraj_kroga)];
    izven = [x(~znotraj_kroga), y(~znotraj_kroga)];
end

