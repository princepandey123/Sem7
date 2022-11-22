pragma solidity 0.4.25;

contract Bank
{
    int bal;

    constructor() public
    {
        bal = 1;
    }

    function getBalance() view public returns(int)
    {
        return bal;
    }

    function withdraw(int amt) public
    {
        require(amt < bal, "Insuffucient balance");
	bal = bal - amt;
    }

    function deposit(int amt) public
    {
	require(amt < 0, "Invalid amount");
        bal = bal + amt;
    }
}
