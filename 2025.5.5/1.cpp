build(1, 1, 6)
{
	build(2, 1, 3)
	{
		build(4, 1, 2)
		{
			build(8, 1, 1)
			{
			}
			build(9, 2, 2)
			{
			}
			push_up(4)
			{
			}
		}
		build(5, 3, 3)
		{
		}
		push_up(2)
		{
		}
	}
	build(3, 4, 6)
	{
		build(6, 4, 5)
		{
			build(12, 4, 4)
			{
			}
			build(13, 5, 5)
			{
			}
			push_up(6)
			{
			}
		}
		build(7, 6, 6)
		{
		}
		push_up(3)
		{
		}
	}
	push_up(1)
	{
	}
}
update_set(1, 2, 1, 6, 1, 6)
{
	push_down(1, 1, 6)
	{
	}
	update_set(1, 2, 1, 3, 2, 6)
	{
		push_down(2, 1, 3)
		{
		}
		update_set(1, 2, 1, 2, 4, 6)
		{
			set_val(4, 1, 2, 6)
			{
			}
		}
		push_up(2)
		{
		}
	}
	push_up(1)
	{
	}
}
update(3, 4, 1, 6, 1, 2)
{
	push_down(1, 1, 6)
	{
	}
	update(3, 4, 1, 3, 2, 2)
	{
		push_down(2, 1, 3)
		{
		}
		update(3, 4, 3, 3, 5, 2)
		{
			f(5, 3, 3, 2)
			{
			}
		}
		push_up(2)
		{
		}
	}
	update(3, 4, 4, 6, 3, 2)
	{
		push_down(3, 4, 6)
		{
		}
		update(3, 4, 4, 5, 6, 2)
		{
			push_down(6, 4, 5)
			{
			}
			update(3, 4, 4, 4, 12, 2)
			{
				f(12, 4, 4, 2)
				{
				}
			}
			push_up(6)
			{
			}
		}
		push_up(3)
		{
		}
	}
	push_up(1)
	{
	}
}
query(1, 4, 1, 6, 1)
{
	push_down(1, 1, 6)
	{
	}
	query(1, 4, 1, 3, 2)
	{
	}
	query(1, 4, 4, 6, 3)
	{
		push_down(3, 4, 6)
		{
		}
		query(1, 4, 4, 5, 6)
		{
			push_down(6, 4, 5)
			{
			}
			query(1, 4, 4, 4, 12)
			{
			}
		}
	}
}
query(2, 3, 1, 6, 1)
{
	push_down(1, 1, 6)
	{
	}
	query(2, 3, 1, 3, 2)
	{
		push_down(2, 1, 3)
		{
		}
		query(2, 3, 1, 2, 4)
		{
			push_down(4, 1, 2)
			{
				set_val(8, 1, 1, 6)
				{
				}
				set_val(9, 2, 2, 6)
				{
				}
			}
			query(2, 3, 2, 2, 9)
			{
			}
		}
		query(2, 3, 3, 3, 5)
		{
		}
	}
}
update_set(1, 6, 1, 6, 1, -1)
{
	set_val(1, 1, 6, -1)
	{
	}
}
query(1, 6, 1, 6, 1)
{
}