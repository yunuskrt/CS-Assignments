import React from 'react'

import { Container, Navbar, Nav } from 'react-bootstrap'

const AppHeader = () => {
	return (
		<Navbar bg='dark' data-bs-theme='dark' style={{ padding: '30px' }}>
			<Container>
				<Navbar.Brand
					href='/'
					style={{ fontSize: '26px', fontWeight: 'bold', letterSpacing: '3px' }}
				>
					<div>Instagram Clone</div>
				</Navbar.Brand>
				<Nav className='me-auto'>
					<Nav.Link href='/users'>Users</Nav.Link>
				</Nav>
			</Container>
		</Navbar>
	)
}

export default AppHeader
